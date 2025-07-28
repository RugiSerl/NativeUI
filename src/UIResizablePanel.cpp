#include "UIResizablePanel.hpp"
#include "utils.hpp"

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone
    if (getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition())) {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_EW);
        canBeTranslated = false;
    } else {
        canBeTranslated = true;
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    }
    UITranslatablePanel::update(boundingBox);
}