#pragma once
#include "../backend/vectors.hpp"
#include "../backend/coordinates.hpp"

namespace property {
    enum class AnchorType {
        MIDDLE,
        LEFT,
        RIGHT,
        TOP,
        BOTTOM,
    };

    /**
     * Represent an origin on screen.
     */
    class Anchor {
    public:
        /**
         * Default anchor is top left
         */
        Anchor();

        /**
         * Constructs a new Anchor.
         */
        Anchor(AnchorType verticalAnchor, AnchorType horizontalAnchor);
        AnchorType verticalAnchor, horizontalAnchor;
    };

    /**
     * Represent a coordinate on screen, but with custom origin (anchor).
     */
    class RelativeCoordinate : public backend::Vector2, Anchor {
    public:
        RelativeCoordinate(float x, float y, Anchor anchor);
        RelativeCoordinate(float x, float y, AnchorType horizontalAnchor, AnchorType verticalAnchor);
        backend::ScreenCoordinate ToScreenCoordinate() const;
    };
}
