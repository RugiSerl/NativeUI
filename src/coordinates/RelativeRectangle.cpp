#include "RelativeRectangle.hpp"
#include "Anchor.hpp"
#include "RelativeCoordinate.hpp"
#include "ScreenRectangle.hpp"
#include <stdexcept>

namespace coordinates {

    RelativeRectangle::RelativeRectangle(float x, float y, float width, float height, Anchor anchor) : position(x, y, anchor), size(width, height) {

    }

    RelativeRectangle::RelativeRectangle(RelativeCoordinate position, backend::RectangleSize size) : position(position), size(size) {

    }

    ScreenRectangle RelativeRectangle::GetScreenRectangle(ScreenRectangle containing) const {
        float newX, newY;

        switch (position.origin.horizontalAnchor) {
            case coordinates::AnchorType::LEFT:
                newX = containing.position.x + position.x;
                break;
            case coordinates::AnchorType::RIGHT:
                newX = containing.position.x + containing.size.GetX() - position.x - size.GetX();
                break;
            case coordinates::AnchorType::MIDDLE:
                newX = containing.position.x + containing.size.GetX()/2.0f + position.x - size.GetX()/2.0f;
                break;
            default:
                throw std::invalid_argument("Invalid anchor used for relativePosition.");
        }

        switch (position.origin.verticalAnchor) {
            case coordinates::AnchorType::TOP:
                newY = containing.position.y + position.y;
                break;
            case coordinates::AnchorType::BOTTOM:
                newY = containing.position.y + containing.size.GetY() - position.y - size.GetY();
                break;
            case coordinates::AnchorType::MIDDLE:
                newY = containing.position.y + containing.size.GetY()/2.0f + position.y - size.GetY()/2.0f;
                break;
            default:
                throw std::invalid_argument("Invalid anchor used for relativePosition.");
        }

        return ScreenRectangle(ScreenCoordinate(newX, newY), size);
    }

    ScreenCoordinate RelativeRectangle::GetScreenCoordinates(ScreenRectangle containing) const {
        return GetScreenRectangle(containing).position;
    }
}
