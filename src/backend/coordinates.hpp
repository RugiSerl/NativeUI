#pragma once
#include "vectors.hpp"
namespace backend {
    /**
     * Represent a position on screen.
     * The origin of that position is the top left corner.
     * The unit is in pixels: 1.0f = 1px.
     * Behaves the same way as a Vector2 but with different type for better typechecking.
     */
    class ScreenCoordinate {
    public:
        float x, y;
        ScreenCoordinate(float x, float y);
        ScreenCoordinate(float xy);
        ScreenCoordinate();
        Vector2 ToVector2() const;

        /**
         * Basic operations
         */
        ScreenCoordinate operator+(const ScreenCoordinate other) const;
        ScreenCoordinate operator-(const ScreenCoordinate other) const;
        float Length() const;
    };
}
