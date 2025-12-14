#include "graphics.hpp"
#include "raylib.h"

namespace backend {
    void DrawRectangle(ScreenCoordinate position, Vector2 size, Color color) {
        DrawRectangleRec(Rectangle{position.x, position.y, size.x, size.y}, color);
    }

    void DrawCircle(ScreenCoordinate center, float radius, int segments, Color color) {
        DrawCircleSector(center.ToVector2(), radius, 0, 360, segments, color);
    }
}
