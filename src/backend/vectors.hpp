#pragma once

#include "raylib.h"
namespace backend {
    class Vector2 : public ::Vector2 {
    public:
        /**
         * Constructors
         */
        Vector2(float x, float y);
        Vector2(float xy);
        Vector2();

        /**
         * Operators
         */
        Vector2 operator+(const Vector2 other) const;
        Vector2 operator-(const Vector2 other) const;

        /**
         * Calculate the euclidian length of the vector.
         */
        float Length() const;
    };

    class Vector3 : public ::Vector3 {
    public:
        Vector3(float x, float y, float z);
        Vector3();

    };

    class Vector4 : public ::Vector4 {
    public:
        Vector4(float x, float y, float z, float w);
        Vector4();

    };


}
