#pragma once

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
}
