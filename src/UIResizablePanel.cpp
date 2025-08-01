#include "UIResizablePanel.hpp"
#include "utils.hpp"
#include "cursor.hpp"

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone
    if (!translating && getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition())) {


        allowedToBeTranslated = false; // resize mode
        RectangleSplitted grid = GetSplittedRectangle(GetAnchoredRect(rect, anchor, boundingBox), getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY));

        // set Cursor appearance when hovering
        if (grid.LeftRect.CheckCollision(raylib::Mouse::GetPosition()) || grid.RightRect.CheckCollision(raylib::Mouse::GetPosition()) ) {
            SetCursor(MOUSE_CURSOR_RESIZE_EW);

        } else if (grid.TopRect.CheckCollision(raylib::Mouse::GetPosition()) || grid.BottomRect.CheckCollision(raylib::Mouse::GetPosition()) ) {
            SetCursor(MOUSE_CURSOR_RESIZE_NS);
        }

        // 1. start resize
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && resizeState.isNone()) {
            if (grid.TopRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Top) {
                resizeState.Top = true;

            } else if (grid.BottomRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Bottom) {
                resizeState.Bottom = true;

            } else if (grid.LeftRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Left) {
                resizeState.Left = true;

            } else if (grid.RightRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Right) {
                resizeState.Right = true;
            }

        }

    } else {
        allowedToBeTranslated = true;
    }

    // 2. update resize
    if (resizeState.Top) {
        //rect.y += GetMouseDelta().y;
        //resizedRect.height -= GetMouseDelta().y;

    } else if (resizeState.Bottom) {
        resizedRect.height += GetMouseDelta().y;

    } else if (resizeState.Left) {
        //resizedRect.width -= GetMouseDelta().x;

    } else if (resizeState.Right) {
        resizedRect.width += GetMouseDelta().x;
    }


    rect.width = Clamp(resizedRect.width, minSize.x, boundingBox.width);
    rect.height = Clamp(resizedRect.height, minSize.y, boundingBox.height);

    // 3. end resize
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !resizeState.isNone()) {
        resizeState.SetToNone();
        // forget true size when resizing is over
        this->resizedRect = this->rect;
    }


    UITranslatablePanel::update(boundingBox);
}