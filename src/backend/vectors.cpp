#include "vectors.hpp"
#include "raylib.h"
#include <cmath>

namespace backend {
    Vector2::Vector2(float x, float y) : ::Vector2{x, y} {

    }

    Vector2::Vector2(float xy) : ::Vector2{xy, xy} {

    }

    Vector2::Vector2() : ::Vector2{0, 0} {

    }

    Vector2 Vector2::operator+(const Vector2 other) const {
        return Vector2(x+other.x, y+other.y);
    }

    Vector2 Vector2::operator-(const Vector2 other) const {
        return Vector2(x-other.x, y-other.y);
    }

    float Vector2::Length() const {
        return sqrt(x*x + y*y);
    }

    Vector3::Vector3(float x, float y, float z) : ::Vector3{x, y, z} {

    }

    Vector3::Vector3() : ::Vector3{0, 0, 0}{

    }

    Vector4::Vector4(float x, float y, float z, float w) : ::Vector4{x, y, z, w} {

    }

    Vector4::Vector4() : ::Vector4{0, 0, 0, 0} {

    }

}
