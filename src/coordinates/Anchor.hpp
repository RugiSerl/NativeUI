#pragma once

namespace coordinates {
    /**
     * Different possibilities of anchors.
     */
    enum class AnchorType {
        MIDDLE,     // Origin in center of containing rect, works for horizontal and vertical anchor
        FILL,       // width (or height) will fill the space of containing rectangle.
        LEFT,       // Origin at the left of containing rect
        RIGHT,      // Origin at the right of containing rect
        TOP,        // Origin at the top of containing rect
        BOTTOM,     // Origin at the bottom of containing rect
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
