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

// warning : unused + not tested (but should be useful I think)
raylib::Rectangle getRectangleIntersection(raylib::Rectangle r1, raylib::Rectangle r2) {
    return raylib::Rectangle(std::max(r1.x, r2.x), std::max(r1.y, r2.y), std::max(0.0f, fabs(r1.x + r1.width / 2 - (r2.x + r2.width / 2)) - fabs(r1.width / 2 + r2.width / 2)), std::max(0.0f, fabs(r1.y + r1.height / 2 - (r2.y + r2.height / 2)) - fabs(r1.height / 2 + r2.height / 2)));
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
