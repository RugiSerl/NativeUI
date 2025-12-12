#include "Rectangle.hpp"
#include "../backend/graphics.hpp"

namespace shape {
    Rectangle::Rectangle(backend::Vector2 size) : size(size) {
    }

    void Rectangle::Render(backend::Vector2 position) {
        backend::DrawRectangle(position, size, backend::Color());
    }

    bool Rectangle::GetPointCollision(backend::Vector2 position, backend::Vector2 point) {
        return true;
    }
}
