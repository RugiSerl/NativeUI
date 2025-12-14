#include "Rectangle.hpp"
#include "Shape.hpp"

namespace shape {
    Rectangle::Rectangle(property::RelativeCoordinate position, backend::Vector2 size) : Shape(position), size(size) {
    }

    void Rectangle::Render(backend::Color color) const {
        backend::DrawRectangle(position.ToScreenCoordinate(), size, color);
    }

    bool Rectangle::GetPointCollision(backend::ScreenCoordinate point) const {
        return point.x > position.x && point.x < position.x + size.x &&
               point.y > position.y && point.y < position.y + size.y;
    }

    backend::Vector2 Rectangle::GetBoundingBoxSize() const {
        return size;
    }
}
