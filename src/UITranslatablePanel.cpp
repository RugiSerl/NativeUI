#include "UITranslatablePanel.hpp"

void UITranslatablePanel::update(raylib::Rectangle boundingBox) {
    UISelectablePanel::update(boundingBox);

    if (UISelectablePanel::getMouseCollision(boundingBox) &&
            IsMouseButtonDown(MOUSE_BUTTON_LEFT) && selected) {
        this->translating = true;

    } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        this->translating = false;
    }

    if (this->translating) {
        // works because the component is anchored to top left.
        this->rect.SetPosition(rect.GetPosition() + raylib::Mouse::GetDelta());
    }
}
