#pragma once
#include "../backend/vectors.hpp"
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
         */
        virtual bool GetPointCollision(backend::Vector2 shapePosition, backend::Vector2 point) = 0;

        /**
         * Render the shape on screen.
         */
        virtual void Render(backend::Vector2 position) = 0;


    };
}
