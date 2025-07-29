#include "cursor.hpp"

void SetCursor(int cursorType) {
    frameCursor = cursorType;
}

void UpdateCursorState() {
    if (cursorState != frameCursor) {
        SetMouseCursor(frameCursor);
        cursorState = frameCursor;
    }

    // set it to default every frame
    frameCursor = MOUSE_CURSOR_DEFAULT;
}