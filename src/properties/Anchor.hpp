#pragma once

namespace property {
    enum class AnchorType {
        MIDDLE,
        LEFT,
        RIGHT,
        TOP,
        BOTTOM,
    };

    class Anchor {
    public:
        Anchor();
        AnchorType verticalAnchor, horizontalAnchor;
    };
}
