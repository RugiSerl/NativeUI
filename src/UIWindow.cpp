#include "UIWindow.hpp"

UIWindow::UIWindow(raylib::Rectangle r, resizableDirections resizableConstraints, Vector2 minSize, UIStylebox normalStylebox, UIStylebox selectedStylebox) :
    UIResizablePanel(r, resizableConstraints, minSize, normalStylebox, selectedStylebox),
    topBar(r, anchor, splitType::VERTICAL_SPLIT, Anchor::TOP, 20, normalStylebox, selectedStylebox) {};


void UIWindow::AddChild(UIComponent* child) {

}

void UIWindow::UpdateAndDraw(raylib::Rectangle boundingBox) {    
    
}