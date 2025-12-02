#include "rectangle.hpp"
#include <stdexcept>

namespace math {
    math::Rectangle getInnerRect(const math::Rectangle rect, const float padding) {
        return getInnerRect(rect, raylib::Vector4(padding, padding, padding, padding));
    }

    math::Rectangle getInnerRect(const math::Rectangle rect, const raylib::Vector4 padding) {
        return {rect.x + padding.x, rect.y + padding.y, rect.width - padding.x - padding.z, rect.height - padding.y - padding.w};
    }

    math::Rectangle getRectangleIntersection(const math::Rectangle r1, const math::Rectangle r2) {
        const auto r1v = VectorRectangle(r1);
        const auto r2v = VectorRectangle(r2);
        return VectorRectangle(std::max(r1v.topLeft.x, r2v.topLeft.x),
                               std::max(r1v.topLeft.y, r2v.topLeft.y),
                               std::min(r1v.bottomRight.x, r2v.bottomRight.x),
                               std::min(r1v.bottomRight.y, r2v.bottomRight.y)).EnsureNotNegativeWidth().ToRectangle();
    }

    math::Rectangle getRectangleUnion(const math::Rectangle r1, const math::Rectangle r2) {
        const auto r1v = VectorRectangle(r1);
        const auto r2v = VectorRectangle(r2);
        return VectorRectangle(std::min(r1v.topLeft.x, r2v.topLeft.x),
                           std::min(r1v.topLeft.y, r2v.topLeft.y),
                           std::max(r1v.bottomRight.x, r2v.bottomRight.x),
                           std::max(r1v.bottomRight.y, r2v.bottomRight.y)).EnsureNotNegativeWidth().ToRectangle();
    }


    RectangleSplit GetSplitRectangle(const math::Rectangle outerRectangle, const math::Rectangle innerRectangle) {
        // Making sure that innerRectangle is inside outerRectangle
        if (innerRectangle.x > outerRectangle.x &&
            innerRectangle.y > outerRectangle.y &&
            innerRectangle.x + innerRectangle.width < outerRectangle.x + outerRectangle.width &&
            innerRectangle.y + innerRectangle.height < outerRectangle.y + outerRectangle.height) {
            // There is probably a better way to do this
            return RectangleSplit{
                .LeftRect =
                math::Rectangle(outerRectangle.x, innerRectangle.y, innerRectangle.x - outerRectangle.x,
                                  innerRectangle.height),
                .RightRect =
                math::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  innerRectangle.height),
                .TopRect =
                math::Rectangle(innerRectangle.x, outerRectangle.y, innerRectangle.width,
                                  innerRectangle.y - outerRectangle.y),
                .BottomRect =
                math::Rectangle(innerRectangle.x, innerRectangle.height + innerRectangle.y, innerRectangle.width,
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .TopLeftCorner =
                math::Rectangle(outerRectangle.x, outerRectangle.y, innerRectangle.x - outerRectangle.x,
                                  innerRectangle.y - outerRectangle.y),
                .TopRightCorner =
                math::Rectangle(innerRectangle.x + innerRectangle.width, outerRectangle.y,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  innerRectangle.y - outerRectangle.y),
                .BottomLeftCorner =
                math::Rectangle(outerRectangle.x, innerRectangle.y + innerRectangle.height,
                                  innerRectangle.x - outerRectangle.x,
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .BottomRightCorner =
                math::Rectangle(innerRectangle.x + innerRectangle.width, innerRectangle.y + innerRectangle.height,
                                  outerRectangle.x + outerRectangle.width - (innerRectangle.x + innerRectangle.width),
                                  outerRectangle.y + outerRectangle.height - (innerRectangle.y + innerRectangle.height)),
                .centerRect = innerRectangle,
            };
        } else {
            throw std::invalid_argument("GetSplittedRectangle: Make sure that innerRectangle is inside of outerRectangle");
        }
    }


    math::Rectangle clampRectangle(math::Rectangle rect, math::Rectangle bounds) {
        return {Clamp(rect.x, bounds.x, std::max(bounds.x + bounds.width - rect.width, 0.0f)),
                                 Clamp(rect.y, bounds.y, std::max(bounds.y + bounds.height - rect.height, 0.0f)),
                                 std::min(rect.width, bounds.width), std::min(rect.height, bounds.height)};
    }


}
