#ifndef __UISELECTABLEPANEL_H__
#define __UISELECTABLEPANEL_H__
#include "UIStylebox.hpp"
#include "UIPanel.hpp"

/**
 * A Panel selectable when clicked upon, and handling overlapping with other selectable panels.
 */
class UISelectablePanel : public UIPanel {
    public:
        UISelectablePanel(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX);
        
        
    protected:
        bool selected;
        UIStylebox selectedStylebox;
        bool getMouseCollision(raylib::Rectangle boundingBox);
        virtual void update(raylib::Rectangle boundingBox) override;
        virtual void draw(raylib::Rectangle boundingBox) override;
        void onSelected();
    };


#endif