#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__
#include "UISelectablePanel.hpp" 
#include <functional>

class UIButton : public UISelectablePanel {
    public:
        /**
         * Constructor for  UIButton.
         * @param r contains size and relative position of item.
         * @param a anchor data of the item.
         * @param callback function to call when the button is pressed.
         * @param normalStylebox default stylebox.
         * @param selectedStylebox
         * @param downStylebox stylebox displayed when the user is holding left mouse button.
         * @param hoveredStylebox stylebox displayed when the mouse is on top of the button.
         */
        UIButton(raylib::Rectangle r, Anchor2 a, std::function<void (void)> callback, UIStylebox normalStylebox, UIStylebox selectedStylebox, UIStylebox hoveredStylebox, UIStylebox downStylebox);
        bool pressed, hovered, down;
        UIStylebox hoveredStylebox, downStylebox;
        std::function<void (void)> onClick;
    protected:
        virtual void update(raylib::Rectangle boundingBox) override;
        virtual void draw(raylib::Rectangle boundingBox) override;
};

#endif