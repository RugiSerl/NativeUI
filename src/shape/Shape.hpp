#pragma once
#include "../backend/vectors.hpp"
#include "../backend/graphics.hpp"

namespace shape {

    enum class ShapeType {
        RECTANGLE,
        ROUNDED_RECTANGLE,
        CIRCLE,
        BEAN,
    };

    /**
     * Abstract class defining graphical shape.
     */
    class Shape {
    public:
        virtual ~Shape() = default;

        /**
         * Get collision between shape and 2d point.
         * The shape is supposed to be anchored from top left.
         */
        virtual bool GetPointCollision(backend::Vector2 point) const  = 0;

        /**
         * Render the shape on screen.
         */
        virtual void Render(backend::Vector2 position, backend::Color color) const  = 0;

        /**
         *
         */
        virtual backend::Vector2 GetBoundingBoxSize() const  = 0;

    };
}
