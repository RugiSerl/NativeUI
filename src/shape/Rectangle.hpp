#pragma once
#include "Shape.hpp"
#include "../backend/rectangles.hpp"

namespace shape {
    class Rectangle : public Shape {
    public:

        Rectangle(property::RelativeCoordinate position, backend::RectangleSize size);

        virtual bool GetPointCollision(property::ScreenRectangle containing, backend::ScreenCoordinate point) const override;

        virtual void RenderFilled(property::ScreenRectangle containing, backend::Color color) const override;

        void RenderLines(property::ScreenRectangle containing, float lineWidth, backend::Color color) const override;

        backend::RectangleSize GetSize() const override;


    };
}
