//
// Created by raphael on 8/17/25.
//

#ifndef NATIVEUI_PANELRESIZABLE_HPP
#define NATIVEUI_PANELRESIZABLE_HPP
#include <cassert>

#include "Panel.hpp"

#define RESIZE_PADDING 10

/**
 * Describes actions possible of Panel.
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
    };

    TransformState() : resizeTop(false), resizeBottom(false), resizeLeft(false), resizeRight(false),
                       translating(false) {
    };

    explicit TransformState(bool value) : resizeTop(value), resizeBottom(value), resizeLeft(value), resizeRight(value),
                                          translating(value) {
    };

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

class PanelResizable : public Panel {
public:
    /**
     * Construct a new PanelResizable.
     * @param position position of the component
     * @param size size of the component.
     * @param anchor Where is the origin of the position
     * @param minimumSize The minimum width and height the component can be resized
     * @param availableTransform transformations allowed by the user
     * @param style normal style of the component
     * @param selectedStyle style of the component when selected
     */
    PanelResizable(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor,
                   raylib::Vector2 minimumSize,
                   TransformState availableTransform = TransformState(true),
                   StyleBox style = DEFAULT_STYLE,
                   StyleBox selectedStyle = DEFAULT_SELECTED_STYLE) : Panel(position, size, anchor, style,
                                                                            selectedStyle, true),
                                                                      availableTransform(availableTransform),
                                                                      ongoingTransform(false),
                                                                      virtualRectangle(position, size),
                                                                      minimumSize(minimumSize) {

    }

    ~PanelResizable() override = default;

protected:
    void update() override;



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

    TransformState availableTransform;

    TransformState ongoingTransform;

    raylib::Rectangle virtualRectangle;

    raylib::Vector2 minimumSize;
};


#endif //NATIVEUI_PANELRESIZABLE_HPP
