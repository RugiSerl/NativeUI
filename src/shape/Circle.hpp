#pragma once

#include "Shape.hpp"
namespace shape {
    class Circle : public Shape {
    public:
        Circle(property::RelativeCoordinate, float radius);

        bool GetPointCollision(property::BoundingBox containing, backend::ScreenCoordinate point) const override;

        void RenderFilled(property::BoundingBox containing, backend::Color color) const override;

        void RenderLines(property::BoundingBox containing, float lineWidth, backend::Color color) const override;

        backend::RectangleSize GetSize() const override;

    private:
        float radius;

    };
}
