#include "Circle.hpp"
#include "Shape.hpp"
#include "../backend/graphics.hpp"


namespace shape {
    Circle::Circle(property::RelativeCoordinate position, float radius) : Shape(position), radius(radius) {

    }

    bool Circle::GetPointCollision(property::BoundingBox containing, backend::ScreenCoordinate point) const {
        return (backend::ScreenCoordinate(radius) - point + GetScreenCoordinates(containing)).Length() < radius;
    }

    void Circle::RenderFilled(property::BoundingBox containing, backend::Color color) const {
        backend::DrawCircle(GetScreenCoordinates(containing)+backend::ScreenCoordinate(radius), radius, 32, color);
    }

    void Circle::RenderLines(property::BoundingBox containing, float lineWidth, backend::Color color) const {
        backend::DrawCircleLines(GetScreenCoordinates(containing)+backend::ScreenCoordinate(radius), radius, 32, lineWidth, color);
    }

    backend::RectangleSize Circle::GetSize() const {
        return backend::RectangleSize(radius*2);
    }
}
