#include "ScreenCoordinate.hpp"
#include <cmath>

namespace coordinates {
    ScreenCoordinate::ScreenCoordinate(float x, float y) : x(x), y(y) {

    }

    ScreenCoordinate::ScreenCoordinate(float xy) : x(xy), y(xy) {

    }

    ScreenCoordinate::ScreenCoordinate() : x(0), y(0) {

    }

    backend::Vector2 ScreenCoordinate::ToVector2() const {
        return backend::Vector2(x, y);
    }

    ScreenCoordinate ScreenCoordinate::operator+(const ScreenCoordinate other) const {
        return ScreenCoordinate(x+other.x, y+other.y);
    }

    ScreenCoordinate ScreenCoordinate::operator-(const ScreenCoordinate other) const {
        return ScreenCoordinate(x-other.x, y-other.y);
    }

    float ScreenCoordinate::Length() const {
        return std::sqrt(x*x + y*y);
    }
}
