#ifndef __UICHECKBOX_H__
#define __UICHECKBOX_H__
#include "UIButton.hpp"


/**
 * @brief Special case of button. Switches between true and false when clicked.
 */
class UICheckbox : public UIButton {
public:


    /**
     * Constructor for UICheckbox.
     * @param r contains size and relative position of item.
     * @param a anchor data of the item.
     * @param callback function to call when the button is pressed.
     * @param normalStylebox default stylebox.
     * @param selectedStylebox
     * @param downStylebox stylebox displayed when the user is holding left mouse button.
     * @param hoveredStylebox stylebox displayed when the mouse is on top of the button.
     */
    UICheckbox(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox, UIStylebox selectedStylebox, UIStylebox hoveredStylebox, UIStylebox downStylebox);
    
    
    bool value;
    
protected:
    virtual void draw(raylib::Rectangle boundingBox) override;
};


#endif