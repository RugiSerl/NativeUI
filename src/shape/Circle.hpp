#pragma once

#include "Shape.hpp"
namespace shape {
    class Circle : public Shape {
    public:
        Circle(property::RelativeCoordinate, float radius);

        bool GetPointCollision(backend::ScreenCoordinate point) const override;

        void Render(backend::Color color) const override;

        backend::Vector2 GetBoundingBoxSize() const override;

    private:
        float radius;

    };
}
