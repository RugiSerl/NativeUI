#include "Circle.hpp"
#include "Shape.hpp"

namespace shape {
    Circle::Circle(property::RelativeCoordinate position, float radius) : Shape(position), radius(radius) {

    }

    bool Circle::GetPointCollision(const property::BoundingBox containing, backend::ScreenCoordinate point) const {
        return (backend::ScreenCoordinate(radius) - point + GetScreenCoordinates(containing)).Length() < radius;
    }

    void Circle::RenderFilled(const property::BoundingBox containing, backend::Color color) const {
        backend::DrawCircle(GetScreenCoordinates(containing)+backend::ScreenCoordinate(radius), radius, 32, color);
    }

    void Circle::RenderLines(const property::BoundingBox containing, const float lineWidth, const backend::Color color) const {
        backend::DrawCircleLines(GetScreenCoordinates(containing)+backend::ScreenCoordinate(radius), radius, 32, lineWidth, color);
    }

    backend::RectangleSize Circle::GetSize() const {
        return backend::RectangleSize(radius*2);
    }
}
