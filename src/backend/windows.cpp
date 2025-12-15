#include "windows.hpp"
#include "raylib.h"
#include "rectangles.hpp"

namespace backend {
    RectangleSize GetWindowSize() {
        return RectangleSize(GetScreenWidth(), GetScreenHeight());
    }
}
