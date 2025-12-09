#pragma once
#include "../backend/Vector.hpp"
#include "Anchor.hpp"

namespace property {
    class Modifier {
    public:

        Modifier() = default;


        /**
         * modifier properties
         */
        backend::Vector2 position, size, minimumSize;
        Anchor anchor;
        backend::Vector4 padding;

    };
}
