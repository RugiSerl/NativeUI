#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include "raylib-cpp.hpp"


/**
 * Represents all the rectangles after a rectangle was splitted in a 3x3 grid.
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
    raylib::Rectangle BottomRightCorner;
    raylib::Rectangle BottomLeftCorner;
};

template<class T> std::vector<T> rotateVector(std::vector<T> vector, int offset);
raylib::Rectangle getInnerRect(raylib::Rectangle, float);
RectangleSplitted GetSplittedRectangle(raylib::Rectangle outerRectangle, raylib::Rectangle innerRectangle);
raylib::Rectangle getRectangleIntersection(raylib::Rectangle r1, raylib::Rectangle r2);
#endif // !__UTILS_H__