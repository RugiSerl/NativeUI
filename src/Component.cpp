//
// Created by raphael on 8/15/25.
//

#include "Component.hpp"

#include <cassert>
#include <iostream>

#include "utils.hpp"

raylib::Rectangle Component::GetScreenSpaceRectangle() const {
    raylib::Rectangle parentRectangle = GetParentRectangle();
    raylib::Rectangle boundingBox;
    LayoutType parentLayout = GetParentLayout();


    if (parentLayout == LayoutType::NONE) {
        boundingBox = GetParentRectangle();
    } else if (parentLayout == LayoutType::COLUMN) {
        raylib::Rectangle previousSiblingRectangle = GetPreviousSiblingRectangle();
        std::cout << "test" << std::endl;
        boundingBox = raylib::Rectangle(parentRectangle.x,
                                            previousSiblingRectangle.y + previousSiblingRectangle.height,
                                            parentRectangle.width,
                                            parentRectangle.y + parentRectangle.height - previousSiblingRectangle.y - previousSiblingRectangle.height);
    } else if (parentLayout == LayoutType::ROW) {
        raylib::Rectangle previousSiblingRectangle = GetPreviousSiblingRectangle();
        boundingBox = raylib::Rectangle(parentRectangle.x + previousSiblingRectangle.width,
                                            previousSiblingRectangle.y,
                                            parentRectangle.x + parentRectangle.width - previousSiblingRectangle.x - previousSiblingRectangle.width,
                                            parentRectangle.height);
    } else {
        throw std::invalid_argument("Incorrect value for Layout");
    }

    return utils::getRectangleIntersection(
        GetAnchoredRect(raylib::Rectangle(modifier.position, modifier.size), modifier.anchor, boundingBox),
        parentRectangle
        );


}

raylib::Rectangle Component::GetParentRectangle() const {
    if (this->parent == nullptr) return GetScreenBoundingbox();
    return this->parent->GetScreenSpaceRectangle();
}

LayoutType Component::GetParentLayout() const {
    if (this->parent==nullptr) return LayoutType::NONE;
    return this->parent->layout;
}

Component * Component::GetParent() const {
    return this->parent;
}

raylib::Rectangle Component::GetPreviousSiblingRectangle() const {
    Component* previousSibling = GetPreviousSibling();
    // This is the first child of the parent. It is more convenient to say it's like the previous child has an empty rectangle for layout.
    if (previousSibling == nullptr) {
        return {GetParentRectangle().GetPosition(), raylib::Vector2(0, 0)};
    }
    return previousSibling->GetScreenSpaceRectangle();

}

Component * Component::GetPreviousSibling() const {
    assert(this->parent != nullptr && "attempting to access the sibling of component which does not have parent.");
    int siblingIndex = parent->GetChildIndex(this)-1;
    if (siblingIndex == -1) {
        return nullptr;
    }
    return GetParent()->GetChild(siblingIndex);
}

Component *Component::GetChild(const int childIndex) const {
    assert(childIndex>=0 && childIndex<children.size() && "Invalid child index");
    return children.at(childIndex);
}


int Component::GetChildIndex(const Component *child) const {
    assert(!children.empty() && "Attempting to retrieve a child of a parent which has no children");
    return std::distance(children.begin(), std::find(children.begin(), children.end(), child));
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
    update();
    draw();
    // this make sure that deletion or additions of children during the update does not affect the order of update.
    std::vector<Component *> backupChildren = children;
    for (Component *child: backupChildren) {
        child->UpdateAndDraw();
    }
}

void Component::SetRect(raylib::Rectangle rect) {
    modifier = modifier
            .setPosition(rect.GetPosition())
            .setSize(rect.GetSize());

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
