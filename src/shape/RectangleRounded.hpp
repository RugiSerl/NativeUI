#pragma once

#include "Rectangle.hpp"
namespace shape {
    class RectangleRounded : public Rectangle {
    public:

        RectangleRounded(property::RelativeCoordinate position, backend::RectangleSize size, float cornerRadius);

        virtual bool GetPointCollision(const property::BoundingBox containing, const backend::ScreenCoordinate point) const override;

        virtual void RenderFilled(const property::BoundingBox containing, const backend::Color color) const override;

        void RenderLines(const property::BoundingBox containing, const float lineWidth, const backend::Color color) const override;

    private:
        float cornerRadius;
    };
}
