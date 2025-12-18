#include "windows.hpp"
#include "raylib.h"
#include "rectangles.hpp"

namespace backend {
    RectangleSize GetWindowSize() {
        return RectangleSize(GetScreenWidth(), GetScreenHeight());
    }

    coordinates::ScreenRectangle GetWindowRect() {
        return coordinates::ScreenRectangle(coordinates::ScreenCoordinate(0, 0), GetWindowSize());
    }
}
