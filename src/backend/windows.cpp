#include "windows.hpp"
#include "raylib.h"
#include "rectangles.hpp"
#include <algorithm>

namespace backend {
    RectangleSize GetWindowSize() {
        return RectangleSize(GetScreenWidth(), GetScreenHeight());
    }

    coordinates::ScreenRectangle GetWindowRect() {
        return coordinates::ScreenRectangle(coordinates::ScreenCoordinate(0, 0), GetWindowSize());
    }

    float GetWindowDPI() {
        auto v = GetWindowScaleDPI();
        return std::max(v.x, v.y);
    }
}
