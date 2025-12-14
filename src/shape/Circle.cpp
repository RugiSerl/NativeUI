#include "Circle.hpp"
#include "Shape.hpp"

namespace shape {
    Circle::Circle(property::RelativeCoordinate position, float radius) : Shape(position), radius(radius) {

    }

    bool Circle::GetPointCollision(backend::ScreenCoordinate point) const {
        return (backend::ScreenCoordinate(radius) - point + (position.ToScreenCoordinate())).Length() < radius;
    }

    void Circle::Render(backend::Color color) const {
        backend::DrawCircle(position.ToScreenCoordinate()+backend::ScreenCoordinate(radius), radius, 32, color);
    }

    backend::Vector2 Circle::GetBoundingBoxSize() const {
        return backend::Vector2(2*radius);
    }
}
