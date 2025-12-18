#pragma once

#include "rectangles.hpp"
#include "../coordinates/ScreenRectangle.hpp"
namespace backend {
    /**
     * Get the size of the window.
     */
    RectangleSize GetWindowSize();

    /**
     * Get the window rectangle as a rectangle with screen coordinates.
     */
    coordinates::ScreenRectangle GetWindowRect();
}
