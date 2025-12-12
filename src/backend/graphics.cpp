#include "graphics.hpp"
#include "raylib.h"

namespace backend {
    void DrawRectangle(Vector2 position, Vector2 size, Color color) {
        DrawRectangleRec(Rectangle{position.x, position.y, size.x, size.y}, color);
    }
}
