#include "UIStylebox.hpp"

UIStylebox::UIStylebox(float borderSize, float edgeRadius, Color fillColor, Color borderColor) {
    this->borderSize = borderSize;
    this->edgeRadius = edgeRadius;
    this->fillColor = fillColor;
    this->borderColor = borderColor;
}

void UIStylebox::draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox) {
    BeginScissorMode(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
    DrawRectangleRounded(GetAnchoredRect(rect, anchor, boundingBox), edgeRadius, 5, fillColor);
    DrawRectangleRoundedLines(GetAnchoredRect(rect, anchor, boundingBox), edgeRadius, 5, borderSize, borderColor);
    EndScissorMode();

}