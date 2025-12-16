#include "Rectangle.hpp"
#include "Shape.hpp"

namespace shape {
    Rectangle::Rectangle(property::RelativeCoordinate position, backend::RectangleSize size) : Shape(position), size(size) {
    }

    void Rectangle::RenderFilled(property::BoundingBox containing, backend::Color color) const {
        backend::DrawRectangle(GetScreenCoordinates(containing), size, color);
    }

    void Rectangle::RenderLines(property::BoundingBox containing, float lineWidth, backend::Color color) const {
        backend::DrawRectangleLines(GetScreenCoordinates(containing), GetSize(), lineWidth, color);
    }

    bool Rectangle::GetPointCollision(property::BoundingBox containing, backend::ScreenCoordinate point) const {
        backend::ScreenCoordinate screenPos = GetScreenCoordinates(containing);
        return point.x > screenPos.x && point.x < screenPos.x + size.GetX() &&
               point.y > screenPos.y && point.y < screenPos.y + size.GetY();
    }

    backend::RectangleSize Rectangle::GetSize() const {
        return size;
    }
}
