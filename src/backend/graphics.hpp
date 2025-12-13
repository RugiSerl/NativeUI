#pragma once
#include "colors.hpp"
#include "vectors.hpp"
namespace backend {
    /**
     * Draws a rectangle on screen.
     */
    void DrawRectangle(Vector2 position, Vector2 size, Color color);

    /**
     * Draws a circle on screen.
     */
    void DrawCircle(Vector2 center, float radius, int segments, Color color);
}
