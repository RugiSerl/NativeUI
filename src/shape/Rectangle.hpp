#pragma once
#include "Shape.hpp"
#include "../backend/rectangles.hpp"

namespace shape {
    class Rectangle : public Shape {
    public:

        Rectangle(property::RelativeCoordinate position, backend::RectangleSize size);

        virtual bool GetPointCollision(const property::BoundingBox containing, backend::ScreenCoordinate point) const override;

        virtual void Render(const property::BoundingBox containing, backend::Color color) const override;

        backend::RectangleSize GetSize() const override;

    protected:
        backend::RectangleSize size;

    };
}
