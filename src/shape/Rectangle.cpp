#include "Rectangle.hpp"
#include "Shape.hpp"
#include "../backend/graphics.hpp"


namespace shape {
    Rectangle::Rectangle(coordinates::RelativeCoordinate position, backend::RectangleSize size) : Shape(position, size) {
    }

    void Rectangle::RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const {
        backend::DrawRectangle(GetScreenCoordinates(containing), size, color);
    }

    void Rectangle::RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const {
        backend::DrawRectangleLines(GetScreenCoordinates(containing), GetSize(), lineWidth, color);
    }

    bool Rectangle::GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const {
        coordinates::ScreenCoordinate screenPos = GetScreenCoordinates(containing);
        return point.x > screenPos.x && point.x < screenPos.x + size.GetX() &&
               point.y > screenPos.y && point.y < screenPos.y + size.GetY();
    }

    backend::RectangleSize Rectangle::GetSize() const {
        return size;
    }
}
