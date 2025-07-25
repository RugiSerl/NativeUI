#include "UIComponent.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iostream>

UIComponent::UIComponent(raylib::Rectangle r, Anchor2 a, UIComponent *parent, UIComponent *root) {
    rect = r;
    anchor = a;
    parent = NULL;
    root = NULL;
    visible = true;
}

void UIComponent::AddChild(UIComponent *child) {
    this->childrenToAdd.push_back(child);
}
void UIComponent::RemoveChild(UIComponent *child) {
    this->childrenToRemove.push_back(child);
}

void UIComponent::addChild(UIComponent *child) {
    child->parent = this;
    child->root = this->root;
    this->children.push_back(child);
}

void UIComponent::removeChild(UIComponent *child) {
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

int UIComponent::GetChildrenCount() {
    return this->children.size();
}

UIComponent *UIComponent::GetChild(int index) {
    return this->children.at(index);
}

// Recursively call update and draw for the component and its children. Call
// this once.
void UIComponent::UpdateAndDraw(raylib::Rectangle boundingBox) {
    if (visible) {
        update(boundingBox);
        draw(boundingBox);
        raylib::Rectangle componentRect = GetAnchoredRect(rect, anchor, boundingBox);

        // Recursively update
        for (UIComponent *child : children) {
            child->UpdateAndDraw(componentRect);
        }

        // Removing / adding new children
        for (UIComponent* childToRemove : childrenToRemove) {
            removeChild(childToRemove);
        }

        for (UIComponent* childToAdd : childrenToAdd) {
            addChild(childToAdd);
        }

        childrenToRemove.clear();
        childrenToAdd.clear();
    }
}

void UIComponent::draw(raylib::Rectangle boundingBox) {
    // overriden by children classes
}

void UIComponent::update(raylib::Rectangle boundingBox) {
    // overriden by children classes
}

void UIComponent::Show() {
    visible = true;
}

void UIComponent::Hide() {
    visible = false;
}