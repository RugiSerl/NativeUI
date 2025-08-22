//
// Created by raphael on 8/19/25.
//

#include "Button.hpp"

void Button::update() {
    Panel::update();
    if (IsHovered()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            down = true;
        } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && down) {
            callback();
            down = false;
        }
    } else {
        down = false;
    }
}

void Button::draw() {
    Panel::draw();

    if (down) {
        downStyle.draw(GetScreenSpaceRectangle(), GetParentRectangle());
    } else if (IsHovered()) {
        hoverStyle.draw(GetScreenSpaceRectangle(), GetParentRectangle());
    }
}
