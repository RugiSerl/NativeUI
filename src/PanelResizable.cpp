//
// Created by raphael on 8/17/25.
//

#include "PanelResizable.hpp"
#include "utils.hpp"

void PanelResizable::update() {
    Panel::update();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsHovered()) {
        startTransform();
    }
    if (!ongoingTransform.IsNone()) {
        updateTransform();
    }
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        endTransform();
    }
}

void PanelResizable::startTransform() {
    raylib::Rectangle screenSpaceRectangle = GetScreenSpaceRectangle();
    RectangleSplit split = GetSplitRectangle(screenSpaceRectangle, getInnerRect(screenSpaceRectangle, RESIZE_PADDING));
    if (split.centerRect.CheckCollision(raylib::Mouse::GetPosition())) {
        ongoingTransform.translating = true;
    }
}

void PanelResizable::updateTransform() {
    if (ongoingTransform.translating) {
        virtualRectangle.SetPosition(virtualRectangle.GetPosition() + raylib::Mouse::GetDelta());
    }

    raylib::Rectangle rect = clampRectangle(virtualRectangle, GetParent()->GetScreenSpaceRectangle());
    position = rect.GetPosition();
    size = rect.GetSize();
}

void PanelResizable::endTransform() {
    virtualRectangle = raylib::Rectangle(position, size);
    ongoingTransform.SetToNone();
}
