#include "Vector.hpp"

namespace backend {
    Vector2::Vector2(float x, float y) {
        x = x;
        y = y;
    }

    Vector2::Vector2() {
        x = 0;
        y = 0;
    }

    Vector2 Vector2::operator=(Vector2 other) {
        return Vector2(other.x, other.y);
    }

    Vector3::Vector3(float x, float y, float z) {
        x = x;
        y = y;
        z = z;
    }

    Vector3::Vector3() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3 Vector3::operator=(Vector3 other) {
        return Vector3(other.x, other.y, other.z);
    }

    Vector4::Vector4(float x, float y, float z, float w) {
        x = x;
        y = y;
        z = z;
        w = w;
    }

    Vector4::Vector4() {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }

    Vector4 Vector4::operator=(Vector4 other) {
        return Vector4(other.x, other.y, other.z, other.w);
    }
}
