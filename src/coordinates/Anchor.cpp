#include "Anchor.hpp"

namespace coordinates {
    Anchor::Anchor() : verticalAnchor(AnchorType::LEFT), horizontalAnchor(AnchorType::TOP) {

    }

    Anchor::Anchor(AnchorType horizontalAnchor, AnchorType verticalAnchor) : verticalAnchor(verticalAnchor), horizontalAnchor(horizontalAnchor) {

    }
}
