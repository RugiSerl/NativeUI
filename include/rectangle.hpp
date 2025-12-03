#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include <algorithm>
#include "external/Rectangle.hpp"
#include "external/raylib-cpp.hpp"
#include "external/raylib.h"
#include "vector2.hpp"

namespace math {

    class Rectangle {
    public:
        float x, y, width, height;
        Rectangle(float x, float y, float w, float h): x(x), y(y), width(w), height(h) {};
        Rectangle(Vector2 position, Vector2 size): x(position.x), y(position.y), width(size.x), height(size.y) {};
        Rectangle(Vector2 size): x(0), y(0), width(size.x), height(size.y) {};
        Rectangle(): x(0), y(0), width(0), height(0) {};
        math::Vector2 GetPosition() const {
            return Vector2(x, y);
        }
        math::Vector2 GetSize() const{
            return Vector2(width, height);
        }
        void SetPosition(Vector2 position) {
            x = position.x;
            y = position.y;
        }
        void SetSize(Vector2 size) {
            width = size.x;
            height = size.y;
        }

        bool CheckCollision(math::Vector2 position) const {
            return position.x >= x && position.x <= x + width && position.y >= y && position.y <= y + height;
        }
        raylib::Rectangle ToRaylibRectangle() const {
            return raylib::Rectangle(x, y, width, height);
        }

    };

    /**
     * @brief Alternative rectangle representation with two points
     *
     */
    class VectorRectangle {
    public:
        math::Vector2 topLeft;
        math::Vector2 bottomRight;
        VectorRectangle(math::Rectangle rect) : topLeft(rect.GetPosition()), bottomRight(rect.x + rect.width, rect.y + rect.height) {};
        VectorRectangle(math::Vector2 topLeft, math::Vector2 bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {};
        VectorRectangle(float x1, float y1, float x2, float y2) : topLeft(x1, y1), bottomRight(x2, y2) {};
        math::Rectangle ToRectangle() {
            return math::Rectangle(topLeft.x, topLeft.y, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
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
     * @param rectangle
     * @param padding
     * @return math::Rectangle
     */
    math::Rectangle getInnerRect(math::Rectangle rectangle, float padding);

    /**
     * @brief Get rectangle inside another with padding value
     *
     * @param rectangle
     * @param padding
     * @return math::Rectangle
     */
    math::Rectangle getInnerRect(math::Rectangle rectangle, raylib::Vector4 padding);


    /**
     * @brief Represents all the rectangles after a rectangle was split in a 3x3 grid.
     *  ________
     * |__|__|__|
     * |__|__|__|
     * |__|__|__|
     */
    struct RectangleSplit {
        // edge rectangles
        math::Rectangle LeftRect;
        math::Rectangle RightRect;
        math::Rectangle TopRect;
        math::Rectangle BottomRect;

        // corner rectangles
        math::Rectangle TopLeftCorner;
        math::Rectangle TopRightCorner;
        math::Rectangle BottomLeftCorner;
        math::Rectangle BottomRightCorner;

        math::Rectangle centerRect;
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
    RectangleSplit GetSplitRectangle(math::Rectangle outerRectangle, math::Rectangle innerRectangle);


    /**
     * @brief Get the intersection rectangle between two rectangles.
     *
     * @param r1
     * @param r2
     * @return math::Rectangle
     */
    math::Rectangle getRectangleIntersection(math::Rectangle r1, math::Rectangle r2);

    /**
     * The smallest rectangle containing both rectangles
     * Not really the union of rectangles.
     */
    math::Rectangle getRectangleUnion(math::Rectangle r1, math::Rectangle r2);

    /**
     * @brief Clamp rectangle inside another
     *
     * @param rect rectangle to clamp
     * @param bounds delimiting rectangle
     * @return math::Rectangle clamped rectangle
     */
    math::Rectangle clampRectangle(math::Rectangle rect, math::Rectangle bounds);


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

    template<class T> std::vector<T> operator+(std::vector<T> v1, std::vector<T> v2) {
        return concatenateVectors(v1, v2);
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
}


#endif // !__UTILS_H__