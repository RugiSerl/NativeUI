#include "inputs.hpp"
#include "raylib.h"

namespace backend {
    coordinates::ScreenCoordinate GetMousePosition() {
        auto pos = ::GetMousePosition();
        return coordinates::ScreenCoordinate(pos.x, pos.y);
    }
}
