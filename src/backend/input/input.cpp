#include "input.hpp"
#include "Mouse.hpp"
#include "vector2.hpp"
#include "Keyboard.hpp"

namespace input {
    math::Vector2 GetMousePosition() {
        return math::Vector2(raylib::Mouse::GetPosition());
    }
    math::Vector2 GetMouseDelta() {
        return math::Vector2(raylib::Mouse::GetDelta());
    }

    char GetKeyChar() {
        return raylib::Keyboard::GetCharPressed();
    }
}
