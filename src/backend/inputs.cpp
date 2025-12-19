#include "inputs.hpp"
#include "raylib.h"

namespace backend {
    coordinates::ScreenCoordinate GetMousePosition() {
        auto pos = ::GetMousePosition();
        return coordinates::ScreenCoordinate(pos.x, pos.y);
    }

    coordinates::ScreenCoordinate GetMouseDelta() {
        auto delta = ::GetMouseDelta();
        return coordinates::ScreenCoordinate(delta.x, delta.y);
    }

    bool IsMousePressed(MOUSE_BUTTON button) {
        return IsMouseButtonPressed(static_cast<int>(button));
    }

    bool IsMouseDown(MOUSE_BUTTON button) {
        return IsMouseButtonDown(static_cast<int>(button));
    }

    bool IsMouseReleased(MOUSE_BUTTON button) {
        return IsMouseButtonReleased(static_cast<int>(button));
    }

    bool IsMouseUp(MOUSE_BUTTON button) {
        return IsMouseButtonUp(static_cast<int>(button));
    }
}
