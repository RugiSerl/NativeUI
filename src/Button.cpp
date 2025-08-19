//
// Created by raphael on 8/19/25.
//

#include "Button.hpp"

void Button::update() {
    Panel::update();
    down = false;
    if (IsHovered()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            callback();
        } else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            down = true;
        }
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
