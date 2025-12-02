#include "mouse.hpp"
#include "Mouse.hpp"

namespace input {
    math::Vector2 GetMousePosition() {
        return math::Vector2(raylib::Mouse::GetPosition());
    }
}