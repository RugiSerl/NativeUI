#ifndef __UITRANSLATABLEPANEL__H__
#define __UITRANSLATABLEPANEL__H__
#include "UISelectablePanel.hpp"


class UITranslatablePanel : public UISelectablePanel {
    public:
        UITranslatablePanel(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UISelectablePanel(r, a, normalStylebox, selectedStylebox) {};

    protected:
        bool translating;
        virtual void update(raylib::Rectangle boundingBox) override;
        virtual void draw(raylib::Rectangle boundingBox) override;
};

#endif // !__UITRANSLATABLEPANEL__H__
