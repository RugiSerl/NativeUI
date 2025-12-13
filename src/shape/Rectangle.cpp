#include "Rectangle.hpp"

namespace shape {
    Rectangle::Rectangle(backend::Vector2 size) : size(size) {
    }

    void Rectangle::Render(backend::Vector2 position, backend::Color color) const {
        backend::DrawRectangle(position, size, color);
    }

    bool Rectangle::GetPointCollision(backend::Vector2 point) const {
        return point.x > 0 && point.x < size.x &&
               point.y > 0 && point.y < size.y;
    }

    backend::Vector2 Rectangle::GetBoundingBoxSize() const {
        return size;
    }
}
