//
// Created by raphael on 8/15/25.
//

#include "Panel.hpp"

#include "graphics.hpp"


void Panel::update() {
    Component::update();
}

void Panel::draw() {
    Component::draw();
    style.draw(GetScreenSpaceRectangle());

}
