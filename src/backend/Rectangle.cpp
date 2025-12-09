#include "Rectangle.hpp"
#include "Vector.hpp"

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
}
