#include "UIResizablePanel.hpp"
#include "utils.hpp"
#include "cursor.hpp"

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone
    if (!translating && getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition())) {

        // resize mode
        allowedToBeTranslated = false;
        RectangleSplitted grid = GetSplittedRectangle(GetAnchoredRect(rect, anchor, boundingBox), getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY));

        // set Cursor appearance when hovering
        if (grid.LeftRect.CheckCollision(raylib::Mouse::GetPosition()) || grid.RightRect.CheckCollision(raylib::Mouse::GetPosition()) ) {
            SetCursor(MOUSE_CURSOR_RESIZE_EW);

        } else if (grid.TopRect.CheckCollision(raylib::Mouse::GetPosition()) || grid.BottomRect.CheckCollision(raylib::Mouse::GetPosition()) ) {
            SetCursor(MOUSE_CURSOR_RESIZE_NS);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && resizeState == resizableDirections::NONE) {
            if (grid.RightRect.CheckCollision(raylib::Mouse::GetPosition())) {
                resizeState = resizableDirections::RIGHT;

            } else if (grid.BottomRect.CheckCollision(raylib::Mouse::GetPosition())) {
                resizeState = resizableDirections::BOTTOM;
            }
        }

    } else {
        allowedToBeTranslated = true;
    }

    switch (resizeState) {
    case resizableDirections::RIGHT:
        resizedRect.width += raylib::Mouse::GetDelta().x;
        break;

    case resizableDirections::BOTTOM:
        resizedRect.height += raylib::Mouse::GetDelta().y;
        break;

    default:
        break;
    }

    rect.width = std::max(minSize.x, resizedRect.width);
    rect.height = std::max(minSize.y, resizedRect.height);

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        resizeState = resizableDirections::NONE;
    }


    UITranslatablePanel::update(boundingBox);
}