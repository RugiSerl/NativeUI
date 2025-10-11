//
// Created by raphael on 8/19/25.
//

#include "Button.hpp"

Button::Button(Modifier modifier, LayoutType layout, std::function<void ()> callback) : Panel(modifier, layout, true),
                                                                                        down(false),
                                                                                        callback(std::move(callback)) {
}


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
