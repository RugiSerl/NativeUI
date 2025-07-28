#include "utils.hpp"

template <class T>
std::vector<T> rotateVector(std::vector<T> vector, unsigned int offset) {
    std::vector<T> newVector(vector.size());
    int i = 0;

    for (T element : vector) {
        newVector.at(i) = vector.at((i + offset) % vector.size());
        i++;
    }

    return newVector;
}

raylib::Rectangle getInnerRect(raylib::Rectangle rect, float width) {
    return raylib::Rectangle(rect.x + width, rect.y + width, rect.width - 2 * width, rect.height - 2 * width);
}

// unused + not tested
raylib::Rectangle getRectangleIntersection(raylib::Rectangle r1, raylib::Rectangle r2) {
    return raylib::Rectangle(std::max(r1.x, r2.x), std::max(r1.y, r2.y), std::max(0.0f, fabs(r1.x + r1.width / 2 - (r2.x + r2.width / 2)) - fabs(r1.width / 2 + r2.width / 2)), std::max(0.0f, fabs(r1.y + r1.height / 2 - (r2.y + r2.height / 2)) - fabs(r1.height / 2 + r2.height / 2)));
}

