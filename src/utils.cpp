#include "utils.hpp"
#include <stdexcept>

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


raylib::Rectangle getRectangleIntersection(raylib::Rectangle r1, raylib::Rectangle r2) {
    VectorRectangle r1v = VectorRectangle(r1);
    VectorRectangle r2v = VectorRectangle(r2);
    return VectorRectangle(std::max(r1v.topLeft.x, r2v.topLeft.x), std::max(r1v.topLeft.y, r2v.topLeft.y), std::min(r1v.bottomRight.x, r2v.bottomRight.x), std::min(r1v.bottomRight.y, r2v.bottomRight.y) ).EnsureNotNegativeWidth().ToRectangle();

}

RectangleSplitted GetSplittedRectangle(raylib::Rectangle outerRectangle, raylib::Rectangle innerRectangle) {
    // Making sure that innerRectangle is inside of outerRectangle
    if (innerRectangle.x > outerRectangle.x &&
            innerRectangle.y > outerRectangle.y &&
            innerRectangle.x + innerRectangle.width < outerRectangle.x + outerRectangle.width &&
            innerRectangle.y + innerRectangle.height < outerRectangle.y + outerRectangle.height) {
        // There is probably a better way to do this
        return RectangleSplitted{
LeftRect:
            raylib::Rectangle(outerRectangle.x, innerRectangle.y, innerRectangle.x - outerRectangle.x, innerRectangle.height),
RightRect:
            raylib::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y, outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width), innerRectangle.height),
TopRect:
            raylib::Rectangle(innerRectangle.x, outerRectangle.y, innerRectangle.width, innerRectangle.y - outerRectangle.y),
BottomRect:
            raylib::Rectangle(innerRectangle.x, innerRectangle.height + innerRectangle.y, innerRectangle.width, outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
TopLeftCorner:
            raylib::Rectangle(outerRectangle.x, outerRectangle.y, innerRectangle.x - outerRectangle.x, innerRectangle.y - outerRectangle.y),
TopRightCorner:
            raylib::Rectangle(innerRectangle.x + innerRectangle.width, outerRectangle.y, outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width), innerRectangle.y - outerRectangle.y),
BottomLeftCorner:
            raylib::Rectangle(outerRectangle.x, innerRectangle.y + innerRectangle.width, innerRectangle.x - outerRectangle.x, outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
BottomRightCorner:
            raylib::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y + innerRectangle.height, outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width), outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
        };

    } else {
        throw std::invalid_argument("GetSplittedRectangle: Make sure that innerRectangle is inside of outerRectangle");
    }

}
