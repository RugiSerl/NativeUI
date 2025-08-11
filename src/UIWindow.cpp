#include "UIWindow.hpp"
#include <iostream>

UIWindow::UIWindow(raylib::Rectangle r, resizableDirections resizableConstraints, Vector2 minSize, UIStylebox normalStylebox, UIStylebox selectedStylebox) :
    UIResizablePanel(r, resizableConstraints, minSize, normalStylebox, selectedStylebox),
    topBar(raylib::Rectangle(0), Anchor2{Anchor::FILL, Anchor::FILL}, splitType::VERTICAL_SPLIT, Anchor::TOP, TOP_BAR_OFFSET, normalStylebox, selectedStylebox),
    closeButton(raylib::Rectangle(0, 0, TOP_BAR_OFFSET, TOP_BAR_OFFSET), Anchor2{Anchor::RIGHT, Anchor::CENTER}, [this]() {
    this->Hide();
}, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, DEFAULT_HOVER_STYLEBOX, DEFAULT_BUTTON_DOWN_STYLEBOX) {
    topBar.AddChild(&closeButton, 0);
};


void UIWindow::AddChild(UIComponent* child) {
    topBar.AddChild(child, 1); // we can only add to the window body
}

void UIWindow::UpdateAndDraw(raylib::Rectangle boundingBox) {
    if (visible) {
        // UIResizablePanel::UpdateAndDraw(boundingBox);
        topBar.UpdateAndDraw(GetScreenSpaceCoordinate(boundingBox));
    }


}

std::string UIWindow::getType() {
    return "UIWindow";
}