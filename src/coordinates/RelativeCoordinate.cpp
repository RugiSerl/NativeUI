#include "RelativeCoordinate.hpp"

namespace coordinates {
    RelativeCoordinate::RelativeCoordinate(float x, float y, Anchor anchor) : x(x), y(y), origin(anchor){

    }

    RelativeCoordinate::RelativeCoordinate(float x, float y, AnchorType horizontalAnchor, AnchorType verticalAnchor) : x(x), y(y), origin(horizontalAnchor, verticalAnchor) {

    }
}
