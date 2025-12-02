//
// Created by raphael on 8/17/25.
//

#ifndef NATIVEUI_PANELTRANSFORMABLE_HPP
#define NATIVEUI_PANELTRANSFORMABLE_HPP
#include <cassert>

#include "Panel.hpp"

#define RESIZE_PADDING 10

namespace UIComponent {
    /**
     * @brief Describes actions possible of Panel.
     */
    class TransformState {
    public:
        bool resizeTop;
        bool resizeBottom;
        bool resizeLeft;
        bool resizeRight;
        bool translating;

        TransformState(bool resizeTop, bool resizeBottom, bool resizeLeft, bool resizeRight,
                       bool translating) : resizeTop(resizeTop), resizeBottom(resizeBottom), resizeLeft(resizeLeft),
                                           resizeRight(resizeRight), translating(translating) {
        }

        TransformState() : resizeTop(false), resizeBottom(false), resizeLeft(false), resizeRight(false),
                           translating(false) {
        }

        explicit TransformState(bool value) : resizeTop(value), resizeBottom(value), resizeLeft(value), resizeRight(value),
                                              translating(value) {
        }

        /**
         * Set everything to false.
         */
        void SetToNone() {
            resizeTop = false;
            resizeBottom = false;
            resizeLeft = false;
            resizeRight = false;
            translating = false;
        }

        /**
         * Is everything false ?
         */
        bool IsNone() const {
            return !(resizeTop || resizeBottom || resizeLeft || resizeRight || translating);
        }
    };

    /**
     * @brief A panel that can be transformed, ie moved or resized.
     * @note transformations can be individually enabled/disabled, using the availableTransform parameter.
     */
    class PanelTransformable : public Panel {
    public:
        /**
         * Construct a new PanelTransformable.
         * @param modifier transformations properties.
         * @param availableTransform transformations allowed by the user
         * @param layout describes how a component should draw its children
         */
        PanelTransformable(Modifier modifier, LayoutType layout, TransformState availableTransform = TransformState(true));

        ~PanelTransformable() override = default;

    protected:
        void update() override;

        // Rectangle which is being transformed without constraints. The rectangle is a constrained version of it.
        math::Rectangle virtualRectangle;


        // The transform this component supports
        TransformState availableTransform;

    private:
        /**
         * called when user clicks on the component, and sets the state of transform.
         */
        void startTransform();

        /**
         * called when a transform is ongoing.
         */
        void updateTransform();

        /**
         * called when user release the mouse.
         */
        void endTransform();

        // The transforms happening as of now.
        TransformState ongoingTransform;
    };
}

#endif //NATIVEUI_PANELTRANSFORMABLE_HPP
