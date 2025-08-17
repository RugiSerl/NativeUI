//
// Created by raphael on 8/17/25.
//

#include "PanelResizable.hpp"

#include <cassert>

#include "utils.hpp"



void PanelResizable::update() {
    Panel::update();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsHovered()) {
        startTransform();
    } else if (!ongoingTransform.IsNone()) {
        updateTransform();
    }
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        endTransform();
    }
}

void PanelResizable::startTransform() {
    ongoingTransform.SetToNone();
    raylib::Rectangle screenSpaceRectangle = GetScreenSpaceRectangle();
    utils::RectangleSplit split = utils::GetSplitRectangle(screenSpaceRectangle, utils::getInnerRect(screenSpaceRectangle, RESIZE_PADDING));

    // Checking center for translation.
    if (split.centerRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.translating = true;

    // Checking edges for resizing.
    } else if (split.TopRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeTop = true;
    } else if (split.BottomRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeBottom = true;
    } else if (split.LeftRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeLeft = true;
    } else if (split.RightRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeRight = true;

    // Checking corners for resizing.
    } else if (split.TopLeftCorner.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeTop = true;
        ongoingTransform.resizeLeft = true;
    } else if (split.TopRightCorner.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeTop = true;
        ongoingTransform.resizeRight = true;
    } else if (split.BottomLeftCorner.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeBottom = true;
        ongoingTransform.resizeLeft = true;
    } else if (split.BottomRightCorner.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.resizeBottom = true;
        ongoingTransform.resizeRight = true;
    }
}

void PanelResizable::updateTransform() {
    assert(!ongoingTransform.IsNone() && "updateTransform() called but no ongoing transform");
    if (ongoingTransform.translating && availableTransform.translating) {
        virtualRectangle.SetPosition(virtualRectangle.GetPosition() + raylib::Mouse::GetDelta());
    }
    if (ongoingTransform.resizeBottom && availableTransform.resizeBottom) {
        virtualRectangle.height += raylib::Mouse::GetDelta().y;
    }

    if (ongoingTransform.resizeRight && availableTransform.resizeRight) {
        virtualRectangle.width += raylib::Mouse::GetDelta().x;
    }


    raylib::Rectangle r = utils::clampRectangle(virtualRectangle, GetParent()->GetScreenSpaceRectangle().GetSize());

    position = r.GetPosition();
    size = r.GetSize();
}

void PanelResizable::endTransform() {
    virtualRectangle = raylib::Rectangle(position, size);
    ongoingTransform.SetToNone();
}
