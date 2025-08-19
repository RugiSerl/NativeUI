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

raylib::Rectangle Component::GetParentRectangle() const {
    if (this->parent == nullptr) return GetScreenBoundingbox();
    return this->parent->GetScreenSpaceRectangle();
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

    // we take this because the component are drawn in a preOrderWalk, so we loop on the reversed order
    std::vector<Component *> preOrderWalk = GetRoot()->GetPreOrderWalk();

    // It is important to loop in a decreasing order because last component are the last to be drawn and so are above the others.
    for (int i = preOrderWalk.size() - 1; i >= 0; i--) {
        if (preOrderWalk.at(i)->GetScreenSpaceRectangle().CheckCollision(mousePosition)) {
            return preOrderWalk.at(i) == this;
        }
    }

    return false;
}


void Component::AddChild(Component *child) {
    assert(child != nullptr && "child added is null");
    assert(!utils::isValueInVector(children, child) && "child is null");
    child->parent = this;
    children.push_back(child);
}

void Component::RemoveChild(Component *child) {
    assert(child != nullptr && "child to remove is null");
    assert(utils::isValueInVector(children, child) && "child to remove is not in children");
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

void Component::SetRect(raylib::Rectangle rect) {
    position = rect.GetPosition();
    size = rect.GetSize();
}

std::vector<Component *> Component::GetPreOrderWalk() {
    std::vector<Component *> preOrderWalk = {this};
    for (Component *child: children) {
        preOrderWalk =  utils::concatenateVectors(preOrderWalk , child->GetPreOrderWalk());
    }
    return preOrderWalk;
}

Component* Component::GetRoot() {
    if (parent==nullptr) {
        return this;
    }
    return GetParent()->GetRoot();
}

void Component::update() {
}

void Component::draw() {
}
