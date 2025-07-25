#include "UIStylebox.hpp"
#include "graphics.hpp"
#include "utils.hpp"

UIStylebox::UIStylebox(float borderThickness, float cornerRadius, Color fillColor, Color borderColor, float innerOffset, float shadowDistance) {
    this->borderThickness = borderThickness;
    this->cornerRadius = cornerRadius;
    this->fillColor = fillColor;
    this->borderColor = borderColor;
    this->shadowDistance = shadowDistance;
    this->innerOffset = innerOffset;
}

void UIStylebox::draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox) {

    BeginScissorMode(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
    raylib::Rectangle anchoredRect = getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), this->innerOffset) ;

    if (shadowDistance > 0) {
        DrawRectangleRounded(anchoredRect, cornerRadius, 5, BLACK);
    }

    DrawRoundedRectangle(anchoredRect, cornerRadius, fillColor);
    DrawRoundedRectangleLines(anchoredRect, cornerRadius, borderColor, borderThickness);
    EndScissorMode();
}