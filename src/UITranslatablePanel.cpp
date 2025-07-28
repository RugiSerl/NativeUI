#include "UITranslatablePanel.hpp"

void UITranslatablePanel::update(raylib::Rectangle boundingBox) {
    UISelectablePanel::update(boundingBox);

    if (UISelectablePanel::getMouseCollision(boundingBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && selected) {
        this->translating = true;
        this->offset = GetAnchoredRect(rect, anchor, boundingBox).GetPosition() - raylib::Mouse::GetPosition();

    } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        this->translating = false;
    }

    if (this->translating) {
        // works because the component is anchored to top left.
        this->rect.SetPosition(raylib::Mouse::GetPosition()-boundingBox.GetPosition()+offset);
    }
}
