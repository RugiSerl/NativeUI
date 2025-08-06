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
        startTranslating(boundingBox);

    } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && translating) {
        stopTranslating();
    }

    if (this->translating) {
        updateTranslating(boundingBox);
    }
    this->rect = getRectangleIntersection(virtualRectangle, raylib::Rectangle(raylib::Vector2(0, 0), boundingBox.GetSize()));
}

void UITranslatablePanel::startTranslating(raylib::Rectangle boundingBox) {
    this->translating = true;
    this->offset = GetAnchoredRect(rect, anchor, boundingBox).GetPosition() - raylib::Mouse::GetPosition();
}

void UITranslatablePanel::updateTranslating(raylib::Rectangle boundingBox) {
    // works because the component is anchored to top left.
    virtualRectangle.SetPosition(raylib::Mouse::GetPosition() - boundingBox.GetPosition() + offset);
}

void UITranslatablePanel::stopTranslating() {
    this->translating = false;
    // forget true position when translation is over
    this->virtualRectangle = this->rect;
}

bool UITranslatablePanel::canBeTranslated(raylib::Rectangle boundingBox) {
    return !inResizeZone && UISelectablePanel::getMouseCollision(boundingBox) && selected;
}

