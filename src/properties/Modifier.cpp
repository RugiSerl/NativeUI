#include "Modifier.hpp"
#include "Anchor.hpp"
#include "Layout.hpp"

namespace property {
    Modifier Modifier::withPosition(backend::Vector2 position) {
        position = position;
        return *this;
    }

    Modifier Modifier::withSize(backend::Vector2 size) {
        size = size;
        return *this;
    }

    Modifier Modifier::withMinimumSize(backend::Vector2 minimumSize) {
        minimumSize = minimumSize;
        return *this;
    }

    Modifier Modifier::withPadding(backend::Vector4 padding) {
        padding = padding;
        return *this;
    }

    Modifier Modifier::withAnchor(property::Anchor anchor) {
        anchor = anchor;
        return *this;
    }

    Modifier Modifier::withLayout(property::Layout layout) {
        layout = layout;
        return *this;
    }
}
