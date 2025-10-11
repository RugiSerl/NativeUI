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
    } else if (parentLayout == LayoutType::ROW) {
        raylib::Rectangle previousSiblingRectangle = GetPreviousSiblingRectangle();
        boundingBox = raylib::Rectangle(parentRectangle.x,
                                            previousSiblingRectangle.y + previousSiblingRectangle.height,
                                            parentRectangle.width,
                                            parentRectangle.y + parentRectangle.height - previousSiblingRectangle.y - previousSiblingRectangle.height);
    } else if (parentLayout == LayoutType::COLUMN) {
        raylib::Rectangle previousSiblingRectangle = GetPreviousSiblingRectangle();
        boundingBox = raylib::Rectangle(previousSiblingRectangle.x + previousSiblingRectangle.width,
                                            parentRectangle.y,
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
    Component* previousSibling = GetPreviousSiblingByInsertionOrder();
    // This is the first child of the parent. It is more convenient to say it's like the previous child has an empty rectangle for layout.
    if (previousSibling == nullptr) {
        return {GetParentRectangle().GetPosition(), raylib::Vector2(0, 0)};
    }
    return previousSibling->GetScreenSpaceRectangle();

}

Component * Component::GetPreviousSiblingByInsertionOrder() const {
    assert(this->parent != nullptr && "attempting to access the sibling of component which does not have parent.");
    int siblingIndex = parent->GetChildIndexInsertion(this)-1;
    if (siblingIndex < 0) {
        return nullptr;
    }
    return GetParent()->GetChild(siblingIndex);
}

Component *Component::GetChild(const int childIndex) const {
    assert(childIndex>=0 && childIndex<childrenOrderedByInsertion.size() && "Invalid child index");
    return childrenOrderedByInsertion.at(childIndex);
}


int Component::GetChildIndexInsertion(const Component *child) const {
    assert(!childrenOrderedByInsertion.empty() && "Attempting to retrieve a child of a parent which has no children");
    return std::distance(childrenOrderedByInsertion.begin(), std::find(childrenOrderedByInsertion.begin(), childrenOrderedByInsertion.end(), child));
}

int Component::GetChildIndexDraw(const Component *child) const {
    assert(!childrenOrderedByDraw.empty() && "Attempting to retrieve a child of a parent which has no children");
    return std::distance(childrenOrderedByDraw.begin(), std::find(childrenOrderedByDraw.begin(), childrenOrderedByDraw.end(), child));

}

int Component::GetChildrenCount() const {
    return this->childrenOrderedByInsertion.size();
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
    assert(!utils::isValueInVector(childrenOrderedByInsertion, child) && "child is null");
    assert(!utils::isValueInVector(childrenOrderedByDraw, child) && "child is null");
    child->parent = this;
    childrenOrderedByInsertion.push_back(child);
    childrenOrderedByDraw.push_back(child);


}

void Component::RemoveChild(Component *child) {
    assert(child != nullptr && "child to remove is null");
    assert(utils::isValueInVector(childrenOrderedByInsertion, child) && "child to remove is not in children");
    assert(utils::isValueInVector(childrenOrderedByDraw, child) && "child to remove is not in children");
    childrenOrderedByInsertion.erase(std::remove(childrenOrderedByInsertion.begin(), childrenOrderedByInsertion.end(), child), childrenOrderedByInsertion.end());
    childrenOrderedByDraw.erase(std::remove(childrenOrderedByDraw.begin(), childrenOrderedByDraw.end(), child), childrenOrderedByDraw.end());

}

void Component::MoveToFront() {
    if (parent == nullptr) {
        return;
    }

    parent->childrenOrderedByDraw.erase(std::remove(parent->childrenOrderedByDraw.begin(), parent->childrenOrderedByDraw.end(), this), parent->childrenOrderedByDraw.end());
    parent->childrenOrderedByDraw.push_back(this);


}

void Component::UpdateAndDraw() {
    update();
    draw();
    // this make sure that deletion or additions of children during the update does not affect the order of update.
    std::vector<Component *> backupChildren (childrenOrderedByInsertion);
    int i = 0;
    for (Component *child: backupChildren) {
        child->UpdateAndDraw();
        std::cout << i << std::endl;
        i++;
    }

    // Small check.
    if (childrenOrderedByDraw.size() != childrenOrderedByInsertion.size()) {
        std::cout << "error: childrenOrderedByInsertion.size() == " <<  childrenOrderedByDraw.size() <<  " and childrenOrderedByDraw.size() == " <<  childrenOrderedByInsertion.size() << std::endl;
        throw std::runtime_error("childrenOrderedByInsertion's length and childrenOrderedByDraw's length do not match: ");
    }
}

void Component::SetRect(raylib::Rectangle rect) {
    modifier = modifier
            .setPosition(rect.GetPosition())
            .setSize(rect.GetSize());

}

std::vector<Component *> Component::GetPreOrderWalk() {
    std::vector<Component *> preOrderWalk = {this};
    for (Component *child: childrenOrderedByInsertion) {
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
