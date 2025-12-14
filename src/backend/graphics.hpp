#pragma once
#include "colors.hpp"
#include "coordinates.hpp"
#include "vectors.hpp"
namespace backend {
    /**
     * Draws a rectangle on screen.
     */
    void DrawRectangle(ScreenCoordinate position, Vector2 size, Color color);

    /**
     * Draws a circle on screen.
     */
    void DrawCircle(ScreenCoordinate center, float radius, int segments, Color color);
}
