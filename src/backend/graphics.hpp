#pragma once
#include "colors.hpp"
#include "coordinates.hpp"
#include "vectors.hpp"
namespace backend {
    /**
     * Draws a rectangle on screen.
     */
    void DrawRectangle(const ScreenCoordinate position, const Vector2 size, const Color color);

    /**
     * Draws a circle on screen.
     */
    void DrawCircle(const ScreenCoordinate center, const float radius, const int segments, const Color color);

    /**
     * Draws a rectangle with rounded corners.
     * The radius of the arcs in the corners is passed as cornerRadius.
     */
    void DrawRoundedRectangle(const ScreenCoordinate position, const Vector2 size, float cornerRadius, const int segments, const Color color);
}
