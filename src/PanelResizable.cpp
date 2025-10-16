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


    // Updating rectangle with a new intermediary one
    raylib::Rectangle r = virtualRectangle;

    // Clamp size so it remains superior to minSize
    r.width = std::max(modifier.minSize.x, virtualRectangle.width);
    r.height = std::max(modifier.minSize.y, virtualRectangle.height);


    SetRect(utils::clampRectangle(r, GetParent()->GetScreenSpaceRectangle().GetSize()));
}

PanelResizable::PanelResizable(Modifier modifier, LayoutType layout, TransformState availableTransform) : Panel(modifier.setAnchor(Anchor2(Anchor::LEFT, Anchor::TOP)), layout, true),
                                                                                                          virtualRectangle(modifier.position, modifier.size),
                                                                                                          availableTransform(availableTransform),
                                                                                                          ongoingTransform(false) {
    assert(!availableTransform.IsNone() && "PanelResizable() : no available transformations provided, just use panel.");
    assert(modifier.minSize.x >=0 && modifier.minSize.y>=0 && "PanelResizable() : you must set a minimum size superior to 0.");
    assert(modifier.size.x >= modifier.minSize.x && modifier.size.y>=modifier.minSize.y && "PanelResizable() : The minimum size must be smaller than the initial size.");
}


void PanelResizable::startTransform() {
    ongoingTransform.SetToNone();
    raylib::Rectangle screenSpaceRectangle = GetScreenSpaceRectangle();
    utils::RectangleSplit split = utils::GetSplitRectangle(screenSpaceRectangle, utils::getInnerRect(screenSpaceRectangle, RESIZE_PADDING * raylib::Window::GetScaleDPI().x));

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
    if (ongoingTransform.resizeTop && availableTransform.resizeTop) {
        virtualRectangle.height -= raylib::Mouse::GetDelta().y;
        virtualRectangle.y += raylib::Mouse::GetDelta().y;
    }
    if (ongoingTransform.resizeBottom && availableTransform.resizeBottom) {
        virtualRectangle.height += raylib::Mouse::GetDelta().y;
    }
    if (ongoingTransform.resizeLeft && availableTransform.resizeLeft) {
        virtualRectangle.width -= raylib::Mouse::GetDelta().x;
        virtualRectangle.x += raylib::Mouse::GetDelta().x;
    }
    if (ongoingTransform.resizeRight && availableTransform.resizeRight) {
        virtualRectangle.width += raylib::Mouse::GetDelta().x;
    }
}

void PanelResizable::endTransform() {
    virtualRectangle = raylib::Rectangle(modifier.position, modifier.size);
    ongoingTransform.SetToNone();
}
