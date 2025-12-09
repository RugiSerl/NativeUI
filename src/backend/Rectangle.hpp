#pragma once

#include "Vector.hpp"
#include "raylib.h"
namespace backend {
    class Rectangle : public ::Rectangle {
        Rectangle(float x, float y, float width, float height);
        Rectangle(backend::Vector2 position, backend::Vector2 size);
    };
}
