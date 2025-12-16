#include "Shape.hpp"
#include <stdexcept>

namespace shape {
    Shape::Shape(property::RelativeCoordinate position) : position(position){

    }

    backend::ScreenCoordinate Shape::GetScreenCoordinates(property::BoundingBox containing) const {
        float newX, newY;

        switch (position.origin.horizontalAnchor) {
            case property::AnchorType::LEFT:
                newX = containing.position.x + position.x;
                break;
            case property::AnchorType::RIGHT:
                newX = containing.position.x + containing.size.GetX() - position.x - GetSize().GetX();
                break;
            case property::AnchorType::MIDDLE:
                newX = containing.position.x + containing.size.GetX()/2.0f + position.x - GetSize().GetX()/2.0f;
                break;
            default:
                throw std::invalid_argument("Invalid anchor used for relativePosition.");
        }

        switch (position.origin.verticalAnchor) {
            case property::AnchorType::TOP:
                newY = containing.position.y + position.y;
                break;
            case property::AnchorType::BOTTOM:
                newY = containing.position.y + containing.size.GetY() - position.y - GetSize().GetY();
                break;
            case property::AnchorType::MIDDLE:
                newY = containing.position.y + containing.size.GetY()/2.0f + position.y - GetSize().GetY()/2.0f;
                break;
            default:
                throw std::invalid_argument("Invalid anchor used for relativePosition.");
        }

        return backend::ScreenCoordinate(newX, newY);
    }

}
