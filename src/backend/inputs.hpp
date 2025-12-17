#pragma once
#include "../coordinates/ScreenCoordinate.hpp"
namespace backend {

    /**
     * Retrieve the mouse position from top left of the window. In pixels.
     */
    coordinates::ScreenCoordinate GetMousePosition();
}
