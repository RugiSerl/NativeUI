#pragma once

#include "Shape.hpp"
namespace shape {
    class Circle : public Shape {
    public:
        Circle(property::RelativeCoordinate, float radius);

        bool GetPointCollision(const property::BoundingBox containing, backend::ScreenCoordinate point) const override;

        void RenderFilled(const property::BoundingBox containing, backend::Color color) const override;

        void RenderLines(const property::BoundingBox containing, const float lineWidth, const backend::Color color) const override;

        backend::RectangleSize GetSize() const override;

    private:
        float radius;

    };
}
