#include "UITranslatablePanel.hpp"

void UITranslatablePanel::update(raylib::Rectangle boundingBox) {
    UISelectablePanel::update(boundingBox);
    if (UISelectablePanel::getMouseCollision(boundingBox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && selected) {
        this->translating = true;
    } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        this->translating = false;
    }
    if (this->translating) {
        this->rect.x += raylib::Mouse::GetDelta().x;
        this->rect.y -= raylib::Mouse::GetDelta().y;
    }
    
}

void UITranslatablePanel::draw(raylib::Rectangle boundingBox) {
    if (UISelectablePanel::getMouseCollision(boundingBox)) {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    UISelectablePanel::draw(boundingBox);
}