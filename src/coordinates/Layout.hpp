#pragma once

#include "Layout.hpp"
namespace coordinates {
    enum class LayoutType {
        NONE,
        ROW,
        COLUMN,
    };
    // Only contains one member, but is mandatory to have the default value and no undefined behavior.
    class Layout {
    public:
        Layout();
        LayoutType layout;
    };
}
