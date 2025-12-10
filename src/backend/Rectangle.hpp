#pragma once

#include "Color.hpp"
#include "Vector.hpp"
#include "raylib.h"
namespace backend {
    class Rectangle : public ::Rectangle {
        public:
            Rectangle(float x, float y, float width, float height);
            Rectangle(backend::Vector2 position, backend::Vector2 size);

            /**
             * Simple draw function
             */
            void Draw(backend::Color color);

            /**
             * Draws with rounded corners.
             */
            void Draw(backend::Color color, float cornerRadius);
    };
}
