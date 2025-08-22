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
                   TransformState availableTransform = TransformState(true)) : Panel(position, size, anchor, true),
                                                                               availableTransform(availableTransform),
                                                                               ongoingTransform(false),
                                                                               virtualRectangle(position, size),
                                                                               minimumSize(minimumSize) {
        assert(
            !availableTransform.IsNone() &&
            "PanelResizable() : no available transformations provided, just use panel.");
        assert(
            minimumSize.x >=0 && minimumSize.y>=0 && "PanelResizable() : you must set a minimum size superior to 0.");
        assert(
            size.x >= minimumSize.x && size.y>=minimumSize.y &&
            "PanelResizable() : The minimum size must be smaller than the initial size.");
    }

    ~PanelResizable() override = default;

protected:
    void update() override;

    raylib::Rectangle virtualRectangle;

    raylib::Vector2 minimumSize;

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

    TransformState ongoingTransform;
};


#endif //NATIVEUI_PANELRESIZABLE_HPP
