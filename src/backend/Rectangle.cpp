#include "Rectangle.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "raylib.h"
#include <iostream>

namespace backend {
    Rectangle::Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {

    }

    Rectangle::Rectangle(backend::Vector2 position, backend::Vector2 size) : ::Rectangle{position.x, position.y, size.x, size.y} {

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
