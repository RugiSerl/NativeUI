#include "UIStylebox.hpp"
#include "graphics.hpp"

UIStylebox::UIStylebox(float borderSize, float edgeRadius, Color fillColor, Color borderColor, float shadowDistance) {
    this->borderSize = borderSize;
    this->edgeRadius = edgeRadius;
    this->fillColor = fillColor;
    this->borderColor = borderColor;
    this->shadowDistance = shadowDistance;
}

void UIStylebox::draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox) {

    BeginScissorMode(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
    raylib::Rectangle anchoredRect = GetAnchoredRect(rect, anchor, boundingBox);

    if (shadowDistance > 0) {
        DrawRectangleRounded(anchoredRect, edgeRadius, 5, BLACK);
    }

    DrawRoundedRectangle(anchoredRect, edgeRadius, fillColor);
    //DrawRectangleRoundedLinesEx(anchoredRect, edgeRadius, 5, borderSize, borderColor);
    EndScissorMode();
}