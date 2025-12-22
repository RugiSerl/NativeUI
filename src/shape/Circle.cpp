#include "Circle.hpp"
#include "Shape.hpp"
#include "../backend/graphics.hpp"


namespace shape {
    Circle::Circle(coordinates::RelativeCoordinate position, float radius) : Shape(position, backend::RectangleSize(radius*2, radius*2)), radius(radius) {

    }

    bool Circle::GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const {
        return (coordinates::ScreenCoordinate(radius) - point + GetScreenCoordinates(containing)).Length() < radius;
    }

    void Circle::RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const {
        backend::DrawCircle(GetScreenCoordinates(containing)+coordinates::ScreenCoordinate(radius), radius, 32, color);
    }

    void Circle::RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const {
        backend::DrawCircleLines(GetScreenCoordinates(containing)+coordinates::ScreenCoordinate(radius), radius, 32, lineWidth, color);
    }
}
