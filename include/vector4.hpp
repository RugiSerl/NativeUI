#ifndef __VECTOR_4_HPP__
#define __VECTOR_4_HPP__

#include "Vector4.hpp"
#include "external/Vector2.hpp"
namespace math {
    class Vector4 {
    public:
        float x, y, z, w;
        Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
        Vector4(float xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {};
        Vector4(raylib::Vector4 v) : x(v.x), y(v.y) {};
        Vector4() : x(0), y(0) {};

        Vector4 operator+(Vector4 v2) const {
            return Vector4(x + v2.x, y + v2.y, z + v2.z, w + v2.w);
        }

        Vector4 operator*(float scalar) const {
            return Vector4(scalar * x, scalar * y, scalar * z, scalar * w);
        };
        raylib::Vector4 ToRaylibVector4() const {
            return raylib::Vector4(x, y, z, w);
        }    
    };
}

#endif //__VECTOR_4_HPP__
