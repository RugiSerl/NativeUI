#include "UITranslatablePanel.hpp"
#include "cursor.hpp"

void UITranslatablePanel::update(raylib::Rectangle boundingBox) {
    UISelectablePanel::update(boundingBox);

    // display move cursor on hover
    if (canBeTranslated(boundingBox)) {
        SetCursor(MOUSE_CURSOR_RESIZE_ALL);
    }


    // select / unselect for translating
    if ( IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canBeTranslated(boundingBox)) {
        this->translating = true;
        this->offset = GetAnchoredRect(rect, anchor, boundingBox).GetPosition() - raylib::Mouse::GetPosition();
    } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        this->translating = false;
    }

    // update translation if translating
    if (this->translating) {
        // works because the component is anchored to top left.
        this->rect.SetPosition(raylib::Mouse::GetPosition() - boundingBox.GetPosition() + offset);
    }
}

bool UITranslatablePanel::canBeTranslated(raylib::Rectangle boundingBox) {
    return allowedToBeTranslated && UISelectablePanel::getMouseCollision(boundingBox) && selected;
}

