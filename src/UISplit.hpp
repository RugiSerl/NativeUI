#ifndef __UISPLIT_H__
#define __UISPLIT_H__
#include "UISelectablePanel.hpp"

#define BAR_WIDTH 1 // px

enum splitType {
    VERTICAL_SPLIT,
    HORIZONTAL_SPLIT,
};
/**
 * A panel dividing its content in two part, either left and right or top and bottom.
 */
class UISplit : public UISelectablePanel {
public:
    UISplit(raylib::Rectangle r, Anchor2 a, splitType type, Anchor barAnchor, float barOffset, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX);
    virtual void UpdateAndDraw(raylib::Rectangle BoundingBox = GetScreenBoundingbox()) override;
    void AddChild(UIComponent* child, int side);

protected:
    splitType type;

    // We need to know where the delimitation is
    float barOffset;
    // One of Anchor's member will be FILL. It will depend on the split type.
    Anchor2 barAnchor;

    UISelectablePanel* firstSide;
    UISelectablePanel* secondSide;

};


#endif // !__UISPLIT_H__