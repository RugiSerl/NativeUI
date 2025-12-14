#include "coordinates.hpp"
#include "vectors.hpp"
#include <cmath>

namespace backend {
    ScreenCoordinate::ScreenCoordinate(float x, float y) : x(x), y(y) {

    }

    ScreenCoordinate::ScreenCoordinate(float xy) : x(xy), y(xy) {

    }

    ScreenCoordinate::ScreenCoordinate() : x(0), y(0) {

    }

    Vector2 ScreenCoordinate::ToVector2() const {
        return Vector2(x, y);
    }

    ScreenCoordinate ScreenCoordinate::operator+(const ScreenCoordinate other) const {
        return ScreenCoordinate(x+other.x, y+other.y);
    }

    ScreenCoordinate ScreenCoordinate::operator-(const ScreenCoordinate other) const {
        return ScreenCoordinate(x-other.x, y-other.y);
    }

    float ScreenCoordinate::Length() const {
        return sqrt(x*x + y*y);
    }
}
