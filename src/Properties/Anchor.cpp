#include "Anchor.hpp"
#include <iostream>
#include <stdexcept>
#include "raylib-cpp.hpp"

math::Rectangle GetScreenBoundingbox() {
    return math::Rectangle(0, 0, GetScreenWidth(), GetScreenHeight());
}

math::Rectangle GetAnchoredRect(const math::Rectangle rect, const Anchor2 anchor, math::Rectangle boundingBox) {
    math::Rectangle res(rect.GetSize());
    switch (anchor.horizontal) {
        case LEFT:
            res.x = boundingBox.x + rect.x;
            break;

        case RIGHT:
            res.x = boundingBox.x + boundingBox.width - rect.width - rect.x;
            break;

        case CENTER:
            res.x = boundingBox.x + boundingBox.width / 2.0f - rect.width / 2.0f + rect.x;
            break;

        case FILL:
            res.x = boundingBox.x;
            res.width = boundingBox.width;
            break;

        default:
            throw std::invalid_argument("incorrect value for horizontal anchor");
    }

    switch (anchor.vertical) {
        case TOP:
            res.y = boundingBox.y + rect.y;
            break;

        case BOTTOM:
            res.y = boundingBox.y + boundingBox.height - rect.height - rect.y;
            break;

        case CENTER:
            res.y = boundingBox.y + boundingBox.height / 2.0f - rect.height / 2.0f + rect.y;
            break;

        case FILL:
            res.y = boundingBox.y;
            res.height = boundingBox.height;
            break;

        default:
            throw std::invalid_argument("incorrect value for vertical anchor");
    }

    return res;
}
