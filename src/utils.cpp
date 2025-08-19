#include "utils.hpp"
#include <stdexcept>

namespace utils {
    raylib::Rectangle getInnerRect(const raylib::Rectangle rect, const float padding) {
        return {rect.x + padding, rect.y + padding, rect.width - 2 * padding, rect.height - 2 * padding};
    }


    raylib::Rectangle getRectangleIntersection(const raylib::Rectangle r1, const raylib::Rectangle r2) {
        const auto r1v = VectorRectangle(r1);
        const auto r2v = VectorRectangle(r2);
        return VectorRectangle(std::max(r1v.topLeft.x, r2v.topLeft.x), std::max(r1v.topLeft.y, r2v.topLeft.y),
                               std::min(r1v.bottomRight.x, r2v.bottomRight.x),
                               std::min(r1v.bottomRight.y, r2v.bottomRight.y)).EnsureNotNegativeWidth().ToRectangle();
    }

    RectangleSplit GetSplitRectangle(const raylib::Rectangle outerRectangle, const raylib::Rectangle innerRectangle) {
        // Making sure that innerRectangle is inside outerRectangle
        if (innerRectangle.x > outerRectangle.x &&
            innerRectangle.y > outerRectangle.y &&
            innerRectangle.x + innerRectangle.width < outerRectangle.x + outerRectangle.width &&
            innerRectangle.y + innerRectangle.height < outerRectangle.y + outerRectangle.height) {
            // There is probably a better way to do this
            return RectangleSplit{
                .LeftRect =
                raylib::Rectangle(outerRectangle.x, innerRectangle.y, innerRectangle.x - outerRectangle.x,
                                  innerRectangle.height),
                .RightRect =
                raylib::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  innerRectangle.height),
                .TopRect =
                raylib::Rectangle(innerRectangle.x, outerRectangle.y, innerRectangle.width,
                                  innerRectangle.y - outerRectangle.y),
                .BottomRect =
                raylib::Rectangle(innerRectangle.x, innerRectangle.height + innerRectangle.y, innerRectangle.width,
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .TopLeftCorner =
                raylib::Rectangle(outerRectangle.x, outerRectangle.y, innerRectangle.x - outerRectangle.x,
                                  innerRectangle.y - outerRectangle.y),
                .TopRightCorner =
                raylib::Rectangle(innerRectangle.x + innerRectangle.width, outerRectangle.y,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  innerRectangle.y - outerRectangle.y),
                .BottomLeftCorner =
                raylib::Rectangle(outerRectangle.x, innerRectangle.y + innerRectangle.height,
                                  innerRectangle.x - outerRectangle.x,
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .BottomRightCorner =
                raylib::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y + innerRectangle.height,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .centerRect = innerRectangle,
            };
        } else {
            throw std::invalid_argument("GetSplittedRectangle: Make sure that innerRectangle is inside of outerRectangle");
        }
    }


    raylib::Rectangle clampRectangle(raylib::Rectangle rect, raylib::Rectangle bounds) {
        return {Clamp(rect.x, bounds.x, std::max(bounds.x + bounds.width - rect.width, 0.0f)),
                                 Clamp(rect.y, bounds.y, std::max(bounds.y + bounds.height - rect.height, 0.0f)),
                                 std::min(rect.width, bounds.width), std::min(rect.height, bounds.height)};
    }


}
