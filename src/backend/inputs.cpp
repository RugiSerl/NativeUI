#include "inputs.hpp"
#include "raylib.h"

namespace backend {
    ScreenCoordinate GetMousePosition() {
        auto pos = ::GetMousePosition();
        return ScreenCoordinate(pos.x, pos.y);
    }
}
