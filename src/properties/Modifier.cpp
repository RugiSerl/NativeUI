#include "Modifier.hpp"
#include "Anchor.hpp"
#include "Layout.hpp"

namespace property {
    Modifier Modifier::withPosition(backend::Vector2 position) {
        this->position = position;
        return *this;
    }

    Modifier Modifier::withSize(backend::Vector2 size) {
        this->size = size;
        return *this;
    }

    Modifier Modifier::withMinimumSize(backend::Vector2 minimumSize) {
        this->minimumSize = minimumSize;
        return *this;
    }

    Modifier Modifier::withPadding(backend::Vector4 padding) {
        this->padding = padding;
        return *this;
    }

    Modifier Modifier::withAnchor(property::Anchor anchor) {
        this->anchor = anchor;
        return *this;
    }

    Modifier Modifier::withLayout(property::Layout layout) {
        this->layout = layout;
        return *this;
    }
}
