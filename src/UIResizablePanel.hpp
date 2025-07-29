#ifndef __UIRESIZABLEPANEL_H__
#define __UIRESIZABLEPANEL_H__
#include "UITranslatablePanel.hpp"

#define RESIZE_LENIENCY 10


enum class resizableDirections : u_int8_t {
    NONE = 0,
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8,
};

/**
 * A panel you can resize by dragging the edges.
 */
class UIResizablePanel : public UITranslatablePanel {
public:
    UIResizablePanel(raylib::Rectangle r, resizableDirections resizableConstraints, Vector2 minSize = raylib::Vector2(0, 0), UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UITranslatablePanel(r, normalStylebox, selectedStylebox), resizableConstraints(resizableConstraints), minSize(minSize), resizedRect(rect) {};
protected:
    raylib::Rectangle resizedRect; // rect that is not constrained by minSize
    Vector2 minSize;
    resizableDirections resizeState = resizableDirections::NONE;
    resizableDirections resizableConstraints;
    virtual void update(raylib::Rectangle boundingBox) override;
};


#endif // !__UIRESIZABLEPANEL_H__