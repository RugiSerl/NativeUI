#include "UISelectablePanel.hpp"
#include "utils.hpp"
#include <algorithm>
UISelectablePanel::UISelectablePanel(raylib::Rectangle r, Anchor2 a,
                                     UIStylebox normalStylebox,
                                     UIStylebox selectedStylebox)
    : UIPanel(r, a, normalStylebox), selectedStylebox(selectedStylebox) {
    selected = false;
}

void UISelectablePanel::update(raylib::Rectangle boundingBox) {
    if (parent == NULL) {
        if (raylib::Mouse::IsButtonPressed(MOUSE_BUTTON_LEFT)) {
            selected = GetAnchoredRect(this->rect, this->anchor, boundingBox).CheckCollision(raylib::Mouse::GetPosition());
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
    for (int i = 0; i < this->parent->GetChildrenCount(); i++) {
        if (this->parent->GetChild(i) != this) { // don't deselect ourself (it's stupid)
            // try downcasting object
            UISelectablePanel *selectableCasted = dynamic_cast<UISelectablePanel *>(this->parent->GetChild(i));

            if (selectableCasted) { // is selectable ?
                selectableCasted->selected = false;
            }
        }

    }
}
// Getting mouse collision between component hitbox, but also making sure thatthe component is not behind another component
bool UISelectablePanel::getMouseCollision(raylib::Rectangle boundingBox) {
    for (int i = this->parent->GetChildrenCount() - 1; i >= 0; i--) { // size > 0 btw, since this already counts as a child
        UIComponent *sibling = this->parent->GetChild(i);

        raylib::Rectangle siblingRect = GetAnchoredRect(sibling->rect, sibling->anchor, boundingBox);
        bool siblingColliding = siblingRect.CheckCollision(raylib::Mouse::GetPosition());

        if (siblingColliding && boundingBox.CheckCollision(raylib::Mouse::GetPosition())) {
            return this->parent->GetChild(i) == this;
        }
    }

    return false;
}

void UISelectablePanel::draw(raylib::Rectangle boundingBox) {
    stylebox.draw(rect, anchor, boundingBox);

    if (selected) {
        selectedStylebox.draw(rect, anchor, boundingBox);
    }
}
