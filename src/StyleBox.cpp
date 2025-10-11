//
// Created by raphael on 8/16/25.
//

#include "StyleBox.hpp"

#include <cassert>

#include "graphics.hpp"

StyleBox::StyleBox(Color fillColor, Color borderColor, float borderWidth, float borderRadius) : fillColor(fillColor),
                                                                                                borderColor(borderColor),
                                                                                                borderWidth(borderWidth),
                                                                                                borderRadius(borderRadius) {
}
;

void StyleBox::draw(const raylib::Rectangle rect, raylib::Rectangle scissorRect) const {
    assert(rect.width>=0 && "StyleBox::draw(): negative rectangle width");
    assert(rect.height>=0 && "StyleBox::draw(): negative rectangle height");

    BeginScissorMode(scissorRect.x, scissorRect.y, scissorRect.width, scissorRect.height);
    DrawRoundedRectangle(rect, borderRadius, fillColor);
    DrawRoundedRectangleLines(rect, borderRadius, borderColor, borderWidth);
    EndScissorMode();
}
