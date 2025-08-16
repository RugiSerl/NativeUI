//
// Created by raphael on 8/15/25.
//

#include "Component.hpp"

#include <assert.h>
#include "utils.hpp"

raylib::Rectangle Component::GetScreenSpaceRectangle() const {
    try {
        return GetAnchoredRect(raylib::Rectangle(position, size), anchor, (this->parent == nullptr) ? GetScreenBoundingbox() : parent->GetScreenSpaceRectangle());
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

Component *Component::GetChild(const int childIndex) const {
    assert(childIndex>=0 && childIndex<children.size() && "Invalid child index");
    return children.at(childIndex);
}

bool Component::isHovered() {
    //TODO: replace
    return GetScreenSpaceRectangle().CheckCollision(raylib::Mouse::GetPosition());
}

void Component::AddChild(Component *child) {
    assert(child != nullptr && "child added is null");
    assert(!isValueInVector(children, child) && "child is null");
    child->parent = this;
    children.push_back(child);
}

void Component::RemoveChild(Component *child) {
    assert(child != nullptr && "child to remove is null");
    assert(isValueInVector(children, child) && "child to remove is null");
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void Component::UpdateAndDraw() {
    update();
    draw();
    for (Component *child : children) {
        child->UpdateAndDraw();
    }
}

void Component::update() {
}

void Component::draw() {
}
