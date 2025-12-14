#pragma once
#include "Shape.hpp"

namespace shape {
    class Rectangle : public Shape {
    public:

        Rectangle(property::RelativeCoordinate position, backend::Vector2 size);

        virtual bool GetPointCollision(backend::ScreenCoordinate point) const override;

        virtual void Render(backend::Color color) const override;

        backend::Vector2 GetBoundingBoxSize() const override;

    protected:
        backend::Vector2 size;

    };
}
