#include "Anchor.hpp"

namespace property {
    Anchor::Anchor() : verticalAnchor(AnchorType::LEFT), horizontalAnchor(AnchorType::TOP) {

    }

    Anchor::Anchor(AnchorType horizontalAnchor, AnchorType verticalAnchor) : verticalAnchor(verticalAnchor), horizontalAnchor(horizontalAnchor) {

    }

    RelativeCoordinate::RelativeCoordinate(float x, float y, Anchor anchor) : Vector2(x, y), Anchor(anchor){

    }

    RelativeCoordinate::RelativeCoordinate(float x, float y, AnchorType horizontalAnchor, AnchorType verticalAnchor)
      : Vector2(x, y),
        Anchor(horizontalAnchor, verticalAnchor) {

    }

    backend::ScreenCoordinate RelativeCoordinate::ToScreenCoordinate() const {
        return backend::ScreenCoordinate(x, y);
    }

}
