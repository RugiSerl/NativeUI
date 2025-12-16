#include "Anchor.hpp"

namespace property {
    Anchor::Anchor() : verticalAnchor(AnchorType::LEFT), horizontalAnchor(AnchorType::TOP) {

    }

    Anchor::Anchor(AnchorType horizontalAnchor, AnchorType verticalAnchor) : verticalAnchor(verticalAnchor), horizontalAnchor(horizontalAnchor) {

    }

    RelativeCoordinate::RelativeCoordinate(float x, float y, Anchor anchor) : x(x), y(y), origin(anchor){

    }

    RelativeCoordinate::RelativeCoordinate(float x, float y, AnchorType horizontalAnchor, AnchorType verticalAnchor) : x(x), y(y), origin(horizontalAnchor, verticalAnchor) {

    }

}
