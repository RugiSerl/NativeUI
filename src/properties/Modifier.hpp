#pragma once
#include "../backend/Vector.hpp"
#include "Anchor.hpp"
#include "Layout.hpp"

namespace property {
    class Modifier {
    public:

        Modifier() = default;
        ~Modifier() = default;

        Modifier withPosition(backend::Vector2);

        Modifier withSize(backend::Vector2);

        Modifier withMinimumSize(backend::Vector2);

        Modifier withPadding(backend::Vector4);

        Modifier withAnchor(property::Anchor);

        Modifier withLayout(property::Layout);

        /**
         * modifier properties
         */
        backend::Vector2 position, size, minimumSize;
        backend::Vector4 padding;
        Anchor anchor;
        Layout layout;

    };
}
