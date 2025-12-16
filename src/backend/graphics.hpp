#pragma once
#include "colors.hpp"
#include "coordinates.hpp"
#include "rectangles.hpp"
namespace backend {
    /**
     * Draws a rectangle on screen.
     */
    void DrawRectangle(ScreenCoordinate position, RectangleSize size, Color color);

    /**
     * Draws the lines around the rectangle.
     */
    void DrawRectangleLines(ScreenCoordinate position, RectangleSize size, float lineWidth, Color color);

    /**
     * Draws a circle on screen.
     */
    void DrawCircle(ScreenCoordinate center, float radius, int segments, Color color);

    /**
     * Draws the lines around the circle.
     */
    void DrawCircleLines(ScreenCoordinate center, float radius, int segments, float lineWidth, Color color);

    /**
     * Draws the lines around an arc of a circle.
     */
    void DrawCircleArcLines(ScreenCoordinate center, float radius, float startAngle, float endAngle, int segments, float lineWidth, Color color);

    /**
     * Draws a rectangle with rounded corners.
     * The radius of the arcs in the corners is passed as cornerRadius.
     */
    void DrawRoundedRectangle(ScreenCoordinate position, RectangleSize size, float cornerRadius, int segments, Color color);

    /**
     * Draws the lines around a rectangle with rounded corners.
     */
    void DrawRoundedRectangleLines(ScreenCoordinate position, RectangleSize size, float cornerRadius, float lineWidth, int segments, Color color);
}
