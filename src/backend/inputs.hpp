#pragma once
#include "../coordinates/ScreenCoordinate.hpp"
namespace backend {

    enum class MOUSE_BUTTON {
        LEFT    = 0,       // Mouse button left
        RIGHT   = 1,       // Mouse button right
        MIDDLE  = 2,       // Mouse button middle (pressed wheel)
        SIDE    = 3,       // Mouse button side (advanced mouse device)
        EXTRA   = 4,       // Mouse button extra (advanced mouse device)
        FORWARD = 5,       // Mouse button forward (advanced mouse device)
        BACK    = 6,       // Mouse button back (advanced mouse device)
    };

    /**
     * Retrieve the mouse position from top left of the window. In pixels.
     */
    coordinates::ScreenCoordinate GetMousePosition();

    bool IsMousePressed(MOUSE_BUTTON button);
    bool IsMouseDown(MOUSE_BUTTON button);
    bool IsMouseReleased(MOUSE_BUTTON button);
    bool IsMouseUp(MOUSE_BUTTON button);
}
