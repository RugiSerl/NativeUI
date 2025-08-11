#include "UIButton.hpp"
#include <iostream>

UIButton::UIButton(raylib::Rectangle r, Anchor2 a, std::function<void(void)> callback, UIStylebox normalStylebox, UIStylebox selectedStylebox, UIStylebox hoveredStylebox, UIStylebox downStylebox)
    : UISelectablePanel(r, a, normalStylebox, selectedStylebox),
      hoveredStylebox(hoveredStylebox), downStylebox(downStylebox),
      pressed(false), hovered(false), down(false), onClick(callback) {};

void UIButton::update(raylib::Rectangle boundingBox) {
    UISelectablePanel::update(boundingBox);
    this->hovered = false;

    if (UISelectablePanel::getMouseCollision(boundingBox)) {
        this->hovered = true;

        if (raylib::Mouse::IsButtonPressed(MOUSE_BUTTON_LEFT)) {
            this->down = true;
        }

        if (raylib::Mouse::IsButtonReleased(MOUSE_BUTTON_LEFT) && this->down) {
            this->down = false;
            this->pressed = true; // activates when user releases button
            this->onClick();
        }

    } else {
        this->down = false;
    }
}
void UIButton::draw(raylib::Rectangle boundingBox) {
    UISelectablePanel::draw(boundingBox);

    if (this->down) {
        downStylebox.draw(rect, anchor, boundingBox);

    } else if (this->hovered) {

        hoveredStylebox.draw(rect, anchor, boundingBox);
    }
}


std::string UIButton::getType() {
    return "UIButton";
}
