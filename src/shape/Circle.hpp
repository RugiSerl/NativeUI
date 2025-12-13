#pragma once

#include "Shape.hpp"
namespace shape {
    class Circle : public Shape {
    public:
        Circle(float radius);

        bool GetPointCollision(backend::Vector2 point) const override;

        void Render(backend::Vector2 position, backend::Color color) const override;

        backend::Vector2 GetBoundingBoxSize() const override;

    private:
        float radius;

    };
}
