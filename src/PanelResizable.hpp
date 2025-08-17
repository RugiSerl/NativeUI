//
// Created by raphael on 8/17/25.
//

#ifndef NATIVEUI_PANELRESIZABLE_HPP
#define NATIVEUI_PANELRESIZABLE_HPP
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

    TransformState(bool value) : resizeTop(value), resizeBottom(value), resizeLeft(value), resizeRight(value),
                                 translating(value) {
    };

    void SetToNone() {
        resizeTop = false;
        resizeBottom = false;
        resizeLeft = false;
        resizeRight = false;
        translating = false;
    }

    bool IsNone() {
        return !(resizeTop || resizeBottom || resizeLeft || resizeRight || translating);
    }
};

class PanelResizable : public Panel {
public:
    ;

    PanelResizable(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor, StyleBox style,
                   TransformState availableTransform = TransformState(true),
                   StyleBox selectedStyle = DEFAULT_SELECTED_STYLE) : Panel(position, size, anchor, style,
                                                                            selectedStyle, true),
                                                                      availableTransform(availableTransform),
                                                                      ongoingTransform(false),
                                                                      virtualRectangle(position, size) {
    }

    ~PanelResizable() override = default;

protected:
    virtual void update() override;

    void startTransform();

    void updateTransform();

    void endTransform();

private:
    TransformState availableTransform;

    TransformState ongoingTransform;

    raylib::Rectangle virtualRectangle;
};


#endif //NATIVEUI_PANELRESIZABLE_HPP
