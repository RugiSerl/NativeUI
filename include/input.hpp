#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include "vector2.hpp"

namespace input {
    math::Vector2 GetMousePosition();
    math::Vector2 GetMouseDelta();
    char GetKeyChar();
}

#endif //__INPUT_HPP__
