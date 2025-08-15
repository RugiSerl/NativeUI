//
// Created by raphael on 8/15/25.
//

#include "UIComponent.hpp"

#include <assert.h>

void UIComponent::GetScreenSpaceRectangoe() {
}

bool UIComponent::isHovered() {
}

void UIComponent::AddChild(UIComponent *child) {
    assert(child != nullptr && "child is null");
    child->parent=this;
    children.push_back(child);
}

void UIComponent::update() {
}

void UIComponent::draw() {
}

UIComponent * UIComponent::GetChild(int childIndex) {
    assert(childIndex>=0 && childIndex<children.size() && "Invalid child index");
    return children.at(childIndex);
}
