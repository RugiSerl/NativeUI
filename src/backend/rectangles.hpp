#pragma once

#include "vectors.hpp"
namespace backend {
    /**
     * Similar to Vector 2 but both coordinates must be superior to 0.
     */
    class RectangleSize : private Vector2 {
    public:
        RectangleSize(float x, float y);
        RectangleSize(float xy);
        RectangleSize();

        /**
         * Getters/Setters
         */
        float GetX() const;
        float GetY() const;
        void SetX(const float x);
        void SetY(const float y);

        /**
         * Operators
         */
        RectangleSize operator+(const RectangleSize other) const;
        RectangleSize operator-(const RectangleSize other) const;

    };
}
