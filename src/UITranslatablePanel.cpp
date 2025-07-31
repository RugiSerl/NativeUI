#include "UITranslatablePanel.hpp"
#include "cursor.hpp"
#include "utils.hpp"

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
        // forget true position when translation is over
        this->translatedPosition = this->rect.GetPosition();
    }

    if (this->translating) {
        // works because the component is anchored to top left.
        translatedPosition = raylib::Mouse::GetPosition() - boundingBox.GetPosition() + offset;
    }

    this->rect = clampRectangle(raylib::Rectangle(translatedPosition, rect.GetSize()), boundingBox.GetSize());

}

bool UITranslatablePanel::canBeTranslated(raylib::Rectangle boundingBox) {
    return allowedToBeTranslated && UISelectablePanel::getMouseCollision(boundingBox) && selected;
}

