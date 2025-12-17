#pragma once
#include "Shape.hpp"
#include "../backend/rectangles.hpp"

namespace shape {
    class Rectangle : public Shape {
    public:

        Rectangle(coordinates::RelativeCoordinate position, backend::RectangleSize size);

        virtual bool GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const override;

        virtual void RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const override;

        void RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const override;

        backend::RectangleSize GetSize() const override;


    };
}
