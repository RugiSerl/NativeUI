#ifndef __UIRESIZABLEPANEL_H__
#define __UIRESIZABLEPANEL_H__
#include "UITranslatablePanel.hpp"

#define RESIZE_LENIENCY 10


enum resizableDirections {
    NOT_RESIZABLE = 0,
    RESIZABLE_NORTH = 1,
    RESIZABLE_SOUTH = 2,
    RESIZABLE_EAST = 4,
    RESIZABLE_WEST = 8,
};

/**
 * A panel you can resize by dragging the edges.
 */
class UIResizablePanel : public UITranslatablePanel {
public:
    UIResizablePanel(raylib::Rectangle r, resizableDirections resizableConstraints, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UITranslatablePanel(r, normalStylebox, selectedStylebox), resizableConstraints(resizableConstraints) {};
protected:
    resizableDirections resizeState;
    resizableDirections resizableConstraints;
    virtual void update(raylib::Rectangle boundingBox) override;
};


#endif // !__UIRESIZABLEPANEL_H__