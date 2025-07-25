#ifndef __UICHECKBOX_H__
#define __UICHECKBOX_H__
#include "UIButton.hpp"

class UICheckbox : public UIButton {
public:
    UICheckbox(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox, UIStylebox selectedStylebox, UIStylebox hoveredStylebox, UIStylebox downStylebox);
    bool value;
protected:
    virtual void draw(raylib::Rectangle boundingBox) override;
};


#endif