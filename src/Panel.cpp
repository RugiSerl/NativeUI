//
// Created by raphael on 8/15/25.
//

#include "Panel.hpp"

#include <cassert>
#include <iostream>

Panel::Panel(Modifier modifier, LayoutType layout, bool selectable) : Component(modifier, layout), selectable(selectable), selected(false) {
    assert(modifier.size.x >= 0 && modifier.size.y >= 0 && "Panel() : The width and the height of the component must be positive");
};

void Panel::update() {
    assert(modifier.size.x >= 0 && "width must be greater than 0");
    assert(modifier.size.y >= 0 && "height must be greater than 0");
    Component::update();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        selected = IsHovered() && selectable;
        if (selected) {
            MoveToFront();
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
