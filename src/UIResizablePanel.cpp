#include "UIResizablePanel.hpp"
#include "utils.hpp"
#include "cursor.hpp"
#include <tuple>

void UIResizablePanel::update(raylib::Rectangle boundingBox) {
    // Check if mouse is in resize zone
    inResizeZone = !translating && getMouseCollision(boundingBox) && !getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY).CheckCollision(raylib::Mouse::GetPosition());

    if (inResizeZone && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && resizeState.isNone()) {
        startResizing(boundingBox);
    }


    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !resizeState.isNone()) {
        stopResizing();
    }


    if (!resizeState.isNone()) {
        updateResizing(boundingBox);
    }


    UITranslatablePanel::update(boundingBox);


    // Updating rectangle with a new intermediary one
    raylib::Rectangle r = virtualRectangle;

    // Clamp size so it remains superior to minSize
    r.width = std::max(minSize.x, virtualRectangle.width);
    r.height = std::max(minSize.y, virtualRectangle.height);

    // Clamp position so resizing stops whenever resizing from top or left
    r.x = std::min(r.x, rect.x + rect.width - minSize.x);
    r.y = std::min(r.y, rect.y + rect.height - minSize.y);

    this->rect = clampRectangle(r, raylib::Rectangle(raylib::Vector2(0, 0), boundingBox.GetSize()));


}

void UIResizablePanel::startResizing(raylib::Rectangle boundingBox) {
    RectangleSplitted grid = GetSplittedRectangle(GetAnchoredRect(rect, anchor, boundingBox), getInnerRect(GetAnchoredRect(rect, anchor, boundingBox), RESIZE_LENIENCY));

    // only one of those cases is verified

    // Checking edges
    if (grid.TopRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Top) {
        resizeState.Top = true;

    } else if (grid.BottomRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Bottom) {
        resizeState.Bottom = true;

    } else if (grid.LeftRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Left) {
        resizeState.Left = true;

    } else if (grid.RightRect.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Right) {
        resizeState.Right = true;
    }

    // Checking corners
    else if (grid.TopLeftCorner.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Top && resizableConstraints.Left) {
        resizeState.Left = true;
        resizeState.Top = true;

    } else if (grid.TopRightCorner.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Top && resizableConstraints.Right) {
        resizeState.Right = true;
        resizeState.Top = true;

    } else if (grid.BottomLeftCorner.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Bottom && resizableConstraints.Left) {
        resizeState.Left = true;
        resizeState.Bottom = true;

    } else if (grid.BottomRightCorner.CheckCollision(raylib::Mouse::GetPosition()) && resizableConstraints.Bottom && resizableConstraints.Right) {
        resizeState.Right = true;
        resizeState.Bottom = true;
    }
}

void UIResizablePanel::updateResizing(raylib::Rectangle boundingBox) {
    if (resizeState.Top) {
        virtualRectangle.y += GetMouseDelta().y;
        virtualRectangle.height -= GetMouseDelta().y;
    }

    if (resizeState.Left) {
        virtualRectangle.x += GetMouseDelta().x;
        virtualRectangle.width -= GetMouseDelta().x;
    }

    if (resizeState.Bottom) {
        virtualRectangle.height += GetMouseDelta().y;
    }

    if (resizeState.Right) {
        virtualRectangle.width += GetMouseDelta().x;
    }

}

void UIResizablePanel::stopResizing() {
    resizeState.SetToNone();
    // If we moved the object by resizing top or left we did in a way a translation. So we need to let the translatablePanel know.
    stopTranslating();
}

std::string UIResizablePanel::getType() {
    return "UIResizablePanel";
}

