#include "UISelectablePanel.hpp"
#include "utils.hpp"
#include "UISplit.hpp"
#include <algorithm>
#include <iostream>
UISelectablePanel::UISelectablePanel(raylib::Rectangle r, Anchor2 a,
                                     UIStylebox normalStylebox,
                                     UIStylebox selectedStylebox)
    : UIPanel(r, a, normalStylebox), selectedStylebox(selectedStylebox) {
    selected = false;
}

void UISelectablePanel::update(raylib::Rectangle boundingBox) {
    if (parent == NULL) {
        if (raylib::Mouse::IsButtonPressed(MOUSE_BUTTON_LEFT)) {
            selected = GetScreenSpaceCoordinate(boundingBox).CheckCollision(raylib::Mouse::GetPosition());
        }

        return;

    }

    if (raylib::Mouse::IsButtonPressed(MOUSE_BUTTON_LEFT)) {

        selected = UISelectablePanel::getMouseCollision(boundingBox);
        if (selected) {
            onSelected();

        }
    }
}

void UISelectablePanel::onSelected() {
    if (this->parent == NULL)
        return; // root case


    // in case of overlapping, happening only between two siblings because of the
    // scissor mode restricting area for children, put this element at the end - on
    // top

    // Removing this object from the parent's childrens (poor guy)
    this->parent->RemoveChild(this);

    // Put it back at the end of the children (on top)
    this->parent->AddChild(this);

    // don't forget to unselect siblings (for selectable objects of course)
    for (int i = 0; i < this->parent->GetChildren().size(); i++) {
        if (this->parent->GetChildren().at(i) != this) { // don't deselect ourself (it's stupid)
            // try downcasting object
            if (UISelectablePanel *selectableCasted = dynamic_cast<UISelectablePanel *>(this->parent->GetChildren().at(i)); selectableCasted) { // is selectable ?
                selectableCasted->selected = false;
            }
        }
    }
}
// Getting mouse collision between component hitbox, but also making sure that the component is not behind another component
bool UISelectablePanel::getMouseCollision(raylib::Rectangle boundingBox) {

    // Check if there are no sibling colliding
    for (int i = this->parent->GetChildren().size() - 1; i >= 0; i--) {
        UIComponent *sibling = this->parent->GetChildren().at(i);

        if (sibling->GetScreenSpaceCoordinate(boundingBox).CheckCollision(raylib::Mouse::GetPosition())) {
            return this->parent->GetChildren().at(i) == this && !isBehindChild(boundingBox);
        }
    }

    return false;
}

bool UISelectablePanel::isBehindChild(raylib::Rectangle boundingBox) {
    if (!visible) return false;

    bool isBehind = false;

    for (UIComponent* child : GetChildren()) {
        if (UISelectablePanel *selectableChild = dynamic_cast<UISelectablePanel *>(child); selectableChild) {
            if (GetAnchoredRect(child->rect, child->anchor, GetAnchoredRect(rect, anchor, boundingBox)).CheckCollision(raylib::Mouse::GetPosition())) {
                return true;
            }
        }
    }

    return isBehind;

}

void UISelectablePanel::draw(raylib::Rectangle boundingBox) {
    stylebox.draw(this, boundingBox);

    if (selected) {
        selectedStylebox.draw(this, boundingBox);
    }
}

bool UISelectablePanel::IsSelected() {
    return selected;
}

std::string UISelectablePanel::getType() {
    return "UISelectablePanel";
}
