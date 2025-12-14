#pragma once
#include "../backend/vectors.hpp"
#include "../backend/graphics.hpp"
#include "../properties/Anchor.hpp"

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
        Shape(property::RelativeCoordinate position);

        virtual ~Shape() = default;

        /**
         * Get collision between shape and 2d point.
         * The shape is supposed to be anchored from top left.
         */
        virtual bool GetPointCollision(backend::ScreenCoordinate point) const  = 0;

        /**
         * Render the shape on screen.
         */
        virtual void Render(backend::Color color) const  = 0;

        /**
         * Get the bounding box of the shape, e.g. the smallest box in which the shape can fit.
         * It is not used for rendering nor calculating collision, just for anchoring the shape.
         */
        virtual backend::Vector2 GetBoundingBoxSize() const  = 0;

    protected:
        property::RelativeCoordinate position;

    };
}
