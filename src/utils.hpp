#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include "raylib-cpp.hpp"

/**
 * @brief Alternative rectangle representation with two points
 *
 */
class VectorRectangle {
public:
    raylib::Vector2 topLeft;
    raylib::Vector2 bottomRight;
    VectorRectangle(raylib::Rectangle rect) : topLeft(rect.GetPosition()), bottomRight(rect.x + rect.width, rect.y + rect.height) {};
    VectorRectangle(raylib::Vector2 topLeft, raylib::Vector2 bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {};
    VectorRectangle(float x1, float y1, float x2, float y2) : topLeft(x1, y1), bottomRight(x2, y2) {};
    raylib::Rectangle ToRectangle() {
        return raylib::Rectangle(topLeft.x, topLeft.y, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
    }
    /**
     * @brief clamp rectangle width to 0
     *
     * @return VectorRectangle
     */
    VectorRectangle EnsureNotNegativeWidth() { //
        return VectorRectangle(topLeft.x, topLeft.y, std::max(bottomRight.x, topLeft.x), std::max(bottomRight.y, topLeft.y));
    }

};





template<class T> std::vector<T> rotateVector(std::vector<T> vector, int offset);
raylib::Rectangle getInnerRect(raylib::Rectangle, float);



/**
 * @brief Represents all the rectangles after a rectangle was splitted in a 3x3 grid.
 *  ________
 * |__|__|__|
 * |__|__|__|
 * |__|__|__|
 */
struct RectangleSplitted {
    // edge rectangles
    raylib::Rectangle LeftRect;
    raylib::Rectangle RightRect;
    raylib::Rectangle TopRect;
    raylib::Rectangle BottomRect;

    // corner rectangles
    raylib::Rectangle TopLeftCorner;
    raylib::Rectangle TopRightCorner;
    raylib::Rectangle BottomLeftCorner;
    raylib::Rectangle BottomRightCorner;
};


/**
 * Splits our rectangle into a grid of 9 rectangles, with a rectangle inside it defining the central cell of the grid
 *
 *  ___________
 * |__|______|_|
 * |__|center|_|
 * |__|______|_|
 *
 */
RectangleSplitted GetSplittedRectangle(raylib::Rectangle outerRectangle, raylib::Rectangle innerRectangle);

/**
 * @brief Get the intersection rectangle between two rectangles.
 *
 * @param r1
 * @param r2
 * @return raylib::Rectangle
 */
raylib::Rectangle getRectangleIntersection(raylib::Rectangle r1, raylib::Rectangle r2);

/**
 * @brief Clamp rectangle inside another
 *
 * @param rect rectangle to clamp
 * @param bounds delimiting rectangle
 * @return raylib::Rectangle clamped rectangle
 */
raylib::Rectangle clampRectangle(raylib::Rectangle rect, raylib::Rectangle bounds);

#endif // !__UTILS_H__