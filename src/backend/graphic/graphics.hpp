#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "../../math/rectangle.hpp"

/**
* Draws a rectangle with rounded corners.
* @param rect rectangle to draw
* @param cornerRadius radius of the circle drawn in the corner
*/
void DrawRoundedRectangle(math::Rectangle rect, float cornerRadius, Color color);


/**
 * Draws a rectangle's lines with rounded corners.
 * @param rect rectangle to draw
 * @param cornerRadius radius of the circle drawn in the corner
 */
void DrawRoundedRectangleLines(math::Rectangle rect, float cornerRadius, Color Color, float thickness);


/**
 * Draws the line of an arc of a circle.
 * @param center The center of the circle
 * @param radius The length of the radius
 * @param startAngle The first angle (in radians) of the arc, from the vector (1, 0) and counterclockwise
 * @param stopAngle The last angle (in radians) of the arc, from the vector (1, 0) and counterclockwise
 * @param lineThickness The width of the line
 * @param segments The amount of small lines to draw
 * @param color
 */
void DrawCircleArcLine(math::Vector2 center, float radius, float startAngle, float stopAngle, float lineThickness, int segments, Color color);


#endif // !__GRAPHICS_H__
