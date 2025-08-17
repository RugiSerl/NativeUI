//
// Created by raphael on 8/15/25.
//

#include "Component.hpp"

#include <assert.h>
#include "utils.hpp"

raylib::Rectangle Component::GetScreenSpaceRectangle() const {
    return GetAnchoredRect(raylib::Rectangle(position, size), anchor,
                           (this->parent == nullptr) ? GetScreenBoundingbox() : parent->GetScreenSpaceRectangle());
}

Component * Component::GetParent() const {
    return this->parent;
}

Component *Component::GetChild(const int childIndex) const {
    assert(childIndex>=0 && childIndex<children.size() && "Invalid child index");
    return children.at(childIndex);
}

int Component::GetChildrenCount() const {
    return this->children.size();
}

bool Component::IsHovered(raylib::Vector2 mousePosition) {
    if (parent == nullptr) {
        return GetScreenSpaceRectangle().CheckCollision(mousePosition);
    }

    // It is important to loop in a decreasing order because last component are the last to be drawn and so are above the others.
    for (int i = parent->GetChildrenCount() - 1; i >= 0; i--) {
        if (parent->GetChild(i)->GetScreenSpaceRectangle().CheckCollision(mousePosition)) {
            return parent->GetChild(i) == this // This component is above its siblings.
                   && !IsBehindChild(mousePosition); // This component has no child in front of it.
        }
    }

    return false;
}

bool Component::IsBehindChild(raylib::Vector2 mousePosition) {
    for (Component *child: children) {
        if (child->GetScreenSpaceRectangle().CheckCollision(mousePosition)) {
            return true;
        }
        if (child->IsBehindChild(mousePosition)) {
            return true;
        }
    }
    return false;
}

void Component::AddChild(Component *child) {
    assert(child != nullptr && "child added is null");
    assert(!isValueInVector(children, child) && "child is null");
    child->parent = this;
    children.push_back(child);
}

void Component::RemoveChild(Component *child) {
    assert(child != nullptr && "child to remove is null");
    assert(isValueInVector(children, child) && "child to remove is not in children");
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void Component::UpdateAndDraw() {
    // TODO : add check for loop in tree with a vector for call stack.
    update();
    draw();
    // this make sure that deletion or additions of children during the update does not affect the order of update.
    std::vector<Component *> backupChildren = children;
    for (Component *child: backupChildren) {
        child->UpdateAndDraw();
    }
}

void Component::update() {
}

void Component::draw() {
}
