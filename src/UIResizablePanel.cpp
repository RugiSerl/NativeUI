#include "UIResizablePanel.hpp"
#include "utils.hpp"

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone and not already down
    if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition())) {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_EW);
    } else {
        UITranslatablePanel::update(boundingBox);
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    }
}