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
    return raylib::Rectangle(rect.x + width, rect.y + width,
                             rect.width - 2 * width, rect.height - 2 * width);
}
