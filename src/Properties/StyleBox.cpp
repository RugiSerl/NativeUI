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

void StyleBox::draw(const math::Rectangle rect, const math::Rectangle scissorRect) const {
    assert(rect.width>=0 && "StyleBox::draw(): negative rectangle width");
    assert(rect.height>=0 && "StyleBox::draw(): negative rectangle height");


    float localBorderRadius = std::min(std::min(rect.width / 2, rect.height / 2), borderRadius);

    BeginScissorMode(scissorRect.x, scissorRect.y, scissorRect.width, scissorRect.height);
        DrawRoundedRectangle(rect, localBorderRadius, fillColor);
        DrawRoundedRectangleLines(rect, localBorderRadius, borderColor, borderWidth);
    EndScissorMode();
}
