//
// Created by raphael on 8/15/25.
//

#include "Panel.hpp"

#include <cassert>
#include <iostream>



void Panel::update() {
    assert(size.x >= 0 && "width must be greater than 0");
    assert(size.y >= 0 && "height must be greater than 0");
    Component::update();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        selected = IsHovered() && selectable;
        if (selected) {
            moveToFront();

        }
    }

}

void Panel::draw() {
    Component::draw();

    style.draw(GetScreenSpaceRectangle(), GetParentRectangle());
    if (selected) {
        selectedStyle.draw(GetScreenSpaceRectangle(), GetParentRectangle());
    }

}

void Panel::moveToFront() {
    if (GetParent() == nullptr) return;

    // This will put this as the last element in the parent's children vector.
    // It will be therefore above the others.
    GetParent()->RemoveChild(this);
    GetParent()->AddChild(this);

}
