#pragma once

#include "Rectangle.hpp"
namespace shape {
    class RectangleRounded : public Rectangle {
    public:

        RectangleRounded(property::RelativeCoordinate position, backend::Vector2 size, float cornerRadius);

        virtual bool GetPointCollision(const backend::ScreenCoordinate point) const override;

        virtual void Render(const backend::Color color) const override;

    private:
        float cornerRadius;
    };
}
