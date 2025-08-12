#include "UIComponent.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iostream>
#include "UISplit.hpp"

UIComponent::UIComponent(raylib::Rectangle r, Anchor2 a, UIComponent *parent, UIComponent *root) {
    this->rect = r;
    this->anchor = a;
    this->parent = NULL;
    this->visible = true;
}

void UIComponent::AddChild(UIComponent *child) {
    child->SetParent(this);
    this->childrenToAdd.push_back(child);
}
void UIComponent::RemoveChild(UIComponent *child) {
    this->childrenToRemove.push_back(child);
}

void UIComponent::addChild(UIComponent *child) {
    this->children.push_back(child);
}

void UIComponent::removeChild(UIComponent *child) {
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}


std::vector<UIComponent*> UIComponent::GetChildren() {
    return this->children;
}

void UIComponent::SetParent(UIComponent* p) {
    this->parent = p;
}

int UIComponent::GetChildIndex(UIComponent* child) {
    int i = 0;
    for (UIComponent* otherChild : this->children) {
        if (otherChild==child) return i;
        i++;
    }
    throw std::invalid_argument("Child index not found");
}


void UIComponent::UpdateAndDraw(raylib::Rectangle boundingBox) {
    if (visible) {

        // Removing / adding new children
        for (UIComponent* childToRemove : childrenToRemove) {
            removeChild(childToRemove);
        }

        for (UIComponent* childToAdd : childrenToAdd) {
            addChild(childToAdd);
        }

        childrenToRemove.clear();
        childrenToAdd.clear();

        update(boundingBox);
        draw(boundingBox);
        raylib::Rectangle componentRect = GetScreenSpaceCoordinate(boundingBox);

        // Recursively update
        for (UIComponent* child : children) {
            child->UpdateAndDraw(getRectangleIntersection(componentRect, boundingBox));
        }

        
    }
}

raylib::Rectangle UIComponent::GetScreenSpaceCoordinate(raylib::Rectangle boundingBox) {
    if (this->parent != NULL) {
        // UISplit *splitCasted = dynamic_cast<UISplit *>(this->parent);
        // if (splitCasted) {
        //     return splitCasted->GetSplittedRectangle(boundingBox, splitCasted->GetChildIndex(this));
        // }

    }

    return GetAnchoredRect(rect, anchor, boundingBox);
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

std::string UIComponent::getType() {
    return "UIComponent";
}