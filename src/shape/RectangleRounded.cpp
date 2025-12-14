#include "RectangleRounded.hpp"
#include "Rectangle.hpp"
#include <algorithm>
#include <iostream>

namespace shape {
    RectangleRounded::RectangleRounded(property::RelativeCoordinate position, backend::Vector2 size, float cornerRadius) : Rectangle(position, size), cornerRadius(cornerRadius) {

    }
    /**
     * The collision is calculated on whether the point is close enough to the inner rect, e.g. the smallest rect fitting in the rounded rectangle.
     * Little ascii art:
     *  ____________
     * /_|_ _ _ _ |_\
     * | | inner  | |
     * | | rect   | |
     * |_|_ _ _ _ |_|
     * \_|________|_/
     *  ^----------^--- corners
     */
    bool RectangleRounded::GetPointCollision(const backend::ScreenCoordinate point) const {
        float clampedCornerRadius = std::min(cornerRadius, std::min(size.x, size.y)/2.0f); // Avoid having border radius larger than half of the smallest side.
        backend::ScreenCoordinate screenPos = position.ToScreenCoordinate();
        float clampedX = std::clamp(point.x, screenPos.x+clampedCornerRadius, screenPos.x+size.x-clampedCornerRadius);
        float clampedY = std::clamp(point.y, screenPos.y+clampedCornerRadius, screenPos.y+size.y-clampedCornerRadius);
        return (backend::ScreenCoordinate(clampedX, clampedY) - point).Length() < clampedCornerRadius;
    }

    void RectangleRounded::Render(const backend::Color color) const {
        backend::DrawRoundedRectangle(position.ToScreenCoordinate(), size, cornerRadius, 8, color);
    }
}
