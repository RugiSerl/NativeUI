#pragma once

#include "Rectangle.hpp"
namespace shape {
    class RectangleRounded : public Rectangle {
    public:

        RectangleRounded(coordinates::RelativeCoordinate position, backend::RectangleSize size, float cornerRadius);

        virtual bool GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const override;

        virtual void RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const override;

        void RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const override;

    private:
        float cornerRadius;
    };
}
