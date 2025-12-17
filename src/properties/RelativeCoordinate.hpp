#pragma once

#include "Anchor.hpp"
namespace property {
    /**
     * Represent a coordinate on screen, but with custom origin (anchor).
     */
    class RelativeCoordinate {
    public:
        float x, y;
        Anchor origin;
        RelativeCoordinate(float x, float y, Anchor anchor);
        RelativeCoordinate(float x, float y, AnchorType horizontalAnchor, AnchorType verticalAnchor);
    };
}
