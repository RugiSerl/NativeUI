#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include <algorithm>
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


/**
 * @brief Get rectangle inside another with padding value
 *
 * @param padding
 * @return raylib::Rectangle
 */
raylib::Rectangle getInnerRect(raylib::Rectangle, float padding);


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


// -----------------------------------------------
// Template functions


/**
 * @brief concatenate two vectors
 *
 * @tparam T type of the elements in the vector
 * @param v1 first vector
 * @param v2 second vector
 * @return std::vector<T>
 *
 */
template<class T> std::vector<T> concatenateVectors(std::vector<T> v1, std::vector<T> v2) {
    std::vector<T> v;
    v.reserve(v1.size() + v2.size());

    for (T e1 : v1) {
        v.push_back(e1);
    }

    for (T e2 : v2) {
        v.push_back(e2);
    }

    return v;

}


/**
 * @brief returns whether the vector contains the value
 * 
 * @tparam T type of the array
 * @param vector 
 * @param value 
 */
template<class T> bool isValueInVector(std::vector<T> vector, T value) {
    return std::find(std::begin(vector), std::end(vector), value) != std::end(vector);
}


/**
 * @brief moves all the elements from a vector according to offset
 *
 * @tparam T type of the elements in the vector
 * @param vector
 * @param offset
 * @return std::vector<T>
 */
template<typename T> std::vector<T> rotateVector(std::vector<T> vector, int offset) {
    std::vector<T> newVector(vector.size());
    int i = 0;

    for (T element : vector) {
        newVector.at(i) = vector.at((i + offset) % vector.size());
        i++;
    }

    return newVector;
}

#endif // !__UTILS_H__