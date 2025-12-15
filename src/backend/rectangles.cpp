#include "rectangles.hpp"
#include "vectors.hpp"
#include <algorithm>

namespace backend {
    RectangleSize::RectangleSize(float x, float y) {
        SetX(x);
        SetY(y);
    }

    RectangleSize::RectangleSize(float xy) {
        SetX(xy);
        SetY(xy);
    }

    RectangleSize::RectangleSize() : Vector2(0, 0) {

    }

    float RectangleSize::GetX() const {
        return x;
    }

    float RectangleSize::GetY() const {
        return y;
    }

    void RectangleSize::SetX(const float x) {
        this->x = std::max(0.0f, x);
    }

    void RectangleSize::SetY(const float y) {
        this->y = std::max(0.0f, y);
    }

    RectangleSize RectangleSize::operator+(const RectangleSize other) const {
        return RectangleSize(x+other.x, y+other.y);
    }

        // This indirectly makes sure that x and y are superior to 0.
    RectangleSize RectangleSize::operator-(const RectangleSize other) const {
        return RectangleSize(x-other.x, y-other.y);
    }
}
