#include "input.hpp"
#include "raylib.h"
#include "vectors.hpp"

namespace backend {
    Vector2 GetMousePosition() {
        auto pos = ::GetMousePosition();
        return Vector2(pos.x, pos.y);
    }
}
