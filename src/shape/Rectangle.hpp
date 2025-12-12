#pragma once

#include "Shape.hpp"
namespace shape {
    class Rectangle : public Shape {
    public:

        Rectangle(backend::Vector2 size);

        bool GetPointCollision(backend::Vector2 shapePosition, backend::Vector2 point) override;

        void Render(backend::Vector2 position) override;

    private:
        backend::Vector2 size;

    };
}
