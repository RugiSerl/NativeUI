#pragma once

#include "Rectangle.hpp"
namespace shape {
    class RectangleRounded : public Rectangle {
    public:

        RectangleRounded(property::RelativeCoordinate position, backend::RectangleSize size, float cornerRadius);

        virtual bool GetPointCollision(property::ScreenRectangle containing, backend::ScreenCoordinate point) const override;

        virtual void RenderFilled(property::ScreenRectangle containing, backend::Color color) const override;

        void RenderLines(property::ScreenRectangle containing, float lineWidth, backend::Color color) const override;

    private:
        float cornerRadius;
    };
}
