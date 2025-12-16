#pragma once
#include "colors.hpp"
#include "coordinates.hpp"
#include "rectangles.hpp"
namespace backend {
    /**
     * Draws a rectangle on screen.
     */
    void DrawRectangle(const ScreenCoordinate position, const RectangleSize size, const Color color);

    /**
     * Draws the lines around the rectangle.
     */
    void DrawRectangleLines(const ScreenCoordinate position, const RectangleSize size, const float lineWidth, const Color color);

    /**
     * Draws a circle on screen.
     */
    void DrawCircle(const ScreenCoordinate center, const float radius, const int segments, const Color color);

    /**
     * Draws the lines around the circle.
     */
    void DrawCircleLines(const ScreenCoordinate center, const float radius, const int segments, const float lineWidth, const Color color);

    /**
     * Draws the lines around an arc of a circle.
     */
    void DrawCircleArcLines(const ScreenCoordinate center, const float radius, const float startAngle, const float endAngle, const int segments, const float lineWidth, const Color color);

    /**
     * Draws a rectangle with rounded corners.
     * The radius of the arcs in the corners is passed as cornerRadius.
     */
    void DrawRoundedRectangle(const ScreenCoordinate position, const RectangleSize size, float cornerRadius, const int segments, const Color color);

    /**
     * Draws the lines around a rectangle with rounded corners.
     */
    void DrawRoundedRectangleLines(const ScreenCoordinate position, const RectangleSize size, const float cornerRadius, const float lineWidth, const int segments, const Color color);
}
