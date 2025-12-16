#include "RectangleRounded.hpp"
#include "Rectangle.hpp"
#include <algorithm>
#include <iostream>

namespace shape {
    RectangleRounded::RectangleRounded(property::RelativeCoordinate position, backend::RectangleSize size, float cornerRadius) : Rectangle(position, size), cornerRadius(cornerRadius) {

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
    bool RectangleRounded::GetPointCollision(const property::BoundingBox containing, const backend::ScreenCoordinate point) const {
        float clampedCornerRadius = std::min(cornerRadius, std::min(size.GetX(), size.GetY())/2.0f); // Avoid having border radius larger than half of the smallest side.
        backend::ScreenCoordinate screenPos = GetScreenCoordinates(containing);
        float clampedX = std::clamp(point.x, screenPos.x+clampedCornerRadius, screenPos.x+size.GetX()-clampedCornerRadius);
        float clampedY = std::clamp(point.y, screenPos.y+clampedCornerRadius, screenPos.y+size.GetY()-clampedCornerRadius);
        return (backend::ScreenCoordinate(clampedX, clampedY) - point).Length() < clampedCornerRadius;
    }

    void RectangleRounded::RenderFilled(const property::BoundingBox containing, const backend::Color color) const {
        backend::DrawRoundedRectangle(GetScreenCoordinates(containing), size, cornerRadius, 8, color);
    }

    void RectangleRounded::RenderLines(const property::BoundingBox containing, const float lineWidth, const backend::Color color) const {
        backend::DrawRoundedRectangleLines(GetScreenCoordinates(containing), size, cornerRadius, lineWidth, 8, color);
    }

}
