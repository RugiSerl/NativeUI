#pragma once
#include "../backend/vectors.hpp"
#include "../backend/graphics.hpp"
#include "../properties/Anchor.hpp"
#include "../properties/BoundingBox.hpp"

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
    class Shape {
    public:
        Shape(property::RelativeCoordinate position);

        virtual ~Shape() = default;

        /**
         * Get collision between shape and 2d point.
         * The shape is supposed to be anchored from top left.
         */
        virtual bool GetPointCollision(property::BoundingBox containing, backend::ScreenCoordinate point) const = 0;

        /**
         * Render the shape filled on screen.
         */
        virtual void RenderFilled(property::BoundingBox containing, backend::Color color) const = 0;

        /**
         * Render the lines on the edges of the shapes.
         */
        virtual void RenderLines(property::BoundingBox containing, float lineWidth, backend::Color color) const = 0;

        /**
         * Get the size of the shape.
         */
        virtual backend::RectangleSize GetSize() const = 0;

        /**
         * Get the position of the shape after applying custom anchor. So now in screen coordinates.
         */
        backend::ScreenCoordinate GetScreenCoordinates(property::BoundingBox containing) const;
    protected:

        property::RelativeCoordinate position;

    };
}
