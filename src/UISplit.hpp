#ifndef __UISPLIT_H__
#define __UISPLIT_H__
#include "UISelectablePanel.hpp"

#define BAR_WIDTH 2 // px

enum splitType {
    VERTICAL_SPLIT,
    HORIZONTAL_SPLIT,
};

class UISplit : public UISelectablePanel {
    public:
        UISplit(raylib::Rectangle r, Anchor2 a, splitType type, Anchor barAnchor, float barOffset, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX);
        void UpdateAndDraw(raylib::Rectangle BoundingBox = GetScreenBoundingbox()) override;
    protected:
        splitType type;

        // We need to know where the delimitation is
        float barOffset;
        // One of Anchor's member will be FILL. It will depend on the split type.
        Anchor2 barAnchor;
        
        // we already have UIComponent's children, so by adding this we have now two category.
        // For horizontal split, thoses categories will be left and right
        // For vertical split, thoses categories will be top and bottom
        std::vector<UIComponent*> secondCategoryChildren;
};


#endif // !__UISPLIT_H__