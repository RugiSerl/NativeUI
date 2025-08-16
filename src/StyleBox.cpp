//
// Created by raphael on 8/16/25.
//

#include "StyleBox.hpp"

#include "graphics.hpp"

void StyleBox::draw(const raylib::Rectangle rect) const {
    DrawRoundedRectangle(rect, borderRadius, fillColor);
    DrawRoundedRectangleLines(rect, borderRadius, borderColor, borderWidth);

}
