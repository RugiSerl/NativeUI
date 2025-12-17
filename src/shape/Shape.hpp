#pragma once
#include "../backend/colors.hpp"
#include "../coordinates/RelativeRectangle.hpp"
#include "../coordinates/ScreenRectangle.hpp"

namespace shape {

    enum class ShapeType {
        RECTANGLE,
        ROUNDED_RECTANGLE,
        CIRCLE,
        BEAN,
    };

    /**
     * Abstract class defining graphical shape.
     * It includes a relative coordinate, a coordinate with a custom origin.
     * This also means that it needs a containing bounding box to be drawn.
     * (The custom origin will be place inside that bounding box).
     */
    class Shape : public coordinates::RelativeRectangle {
    public:
        Shape(coordinates::RelativeCoordinate position, backend::RectangleSize size);

        virtual ~Shape() = default;

        /**
         * Get collision between shape and 2d point.
         * The shape is supposed to be anchored from top left.
         */
        virtual bool GetPointCollision(coordinates::ScreenRectangle containing, coordinates::ScreenCoordinate point) const = 0;

        /**
         * Render the shape filled on screen.
         */
        virtual void RenderFilled(coordinates::ScreenRectangle containing, backend::Color color) const = 0;

        /**
         * Render the lines on the edges of the shapes.
         */
        virtual void RenderLines(coordinates::ScreenRectangle containing, float lineWidth, backend::Color color) const = 0;

        /**
         * Get the size of the shape.
         */
        virtual backend::RectangleSize GetSize() const = 0;
    };
}
