#include "UIStylebox.hpp"
#include "graphics.hpp"

UIStylebox::UIStylebox(float borderThickness, float cornerRadius, Color fillColor, Color borderColor, float shadowDistance) {
    this->borderThickness = borderThickness;
    this->cornerRadius = cornerRadius;
    this->fillColor = fillColor;
    this->borderColor = borderColor;
    this->shadowDistance = shadowDistance;
}

void UIStylebox::draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox) {

    BeginScissorMode(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
    raylib::Rectangle anchoredRect = GetAnchoredRect(rect, anchor, boundingBox);

    if (shadowDistance > 0) {
        DrawRectangleRounded(anchoredRect, cornerRadius, 5, BLACK);
    }

    DrawRoundedRectangle(anchoredRect, cornerRadius, fillColor);
    DrawRoundedRectangleLines(anchoredRect, cornerRadius, borderColor, borderThickness);
    EndScissorMode();
}