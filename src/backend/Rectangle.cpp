#include "Rectangle.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "raylib.h"

namespace backend {
    Rectangle::Rectangle(float x, float y, float width, float height) {
        x = x;
        y = y;
        width = width;
        height = height;
    }

    Rectangle::Rectangle(backend::Vector2 position, backend::Vector2 size) {
        x = position.x;
        y = position.y;
        width = size.x;
        height = size.y;
    }

    void Rectangle::Draw(backend::Color color) {
        DrawRectangleRec(*this, color);
    }

    void Rectangle::Draw(backend::Color color, float cornerRadius) {
        if (cornerRadius <= 0) {
            Draw(color); // Use standard drawing without rounded corners.
            return;
        }
    }
}
