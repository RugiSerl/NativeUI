//
// Created by raphael on 8/15/25.
//

#include "Panel.hpp"

#include <iostream>



void Panel::update() {
    Component::update();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        selected = IsHovered();
        if (selected) {
            moveToFront();
        }
    }
}

void Panel::draw() {
    Component::draw();
    style.draw(GetScreenSpaceRectangle());
    if (selected) {
        selectedStyle.draw(GetScreenSpaceRectangle());
    }

}

void Panel::moveToFront() {
    if (GetParent() == nullptr) return;
    GetParent()->RemoveChild(this);
    GetParent()->AddChild(this);

}
