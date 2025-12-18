#pragma once

#include "Shape.hpp"
namespace shape {
    class Circle : public Shape {
    public:
        Circle(coordinates::RelativeCoordinate position, float radius);

        bool GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const override;

        void RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const override;

        void RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const override;

        backend::RectangleSize GetSize() const override;

    private:
        float radius;

    };
}
