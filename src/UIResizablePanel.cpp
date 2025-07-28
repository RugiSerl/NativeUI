#include "UIResizablePanel.hpp"
#include "utils.hpp"

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone
    if (!translating && getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition())) {
        canBeTranslated = false;
        RectangleSplitted splitted = GetSplittedRectangle(GetAnchoredRect(rect, anchor, boundingBox), getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY));
        splitted.LeftRect.Draw(BLUE);

    } else {
        canBeTranslated = true;
    }

    UITranslatablePanel::update(boundingBox);
}