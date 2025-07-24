#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__
#include "UISelectablePanel.hpp" 

class UIButton : public UISelectablePanel {
    public:
        UIButton(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox, UIStylebox selectedStylebox, UIStylebox hoveredStylebox, UIStylebox downStylebox);
        bool pressed, hovered, down;
        UIStylebox hoveredStylebox, downStylebox;
        static void OnClickCallback(UIButton* thisPointer); // TODO
    protected:
        virtual void update(raylib::Rectangle boundingBox) override;
        virtual void draw(raylib::Rectangle boundingBox) override;
};

#endif