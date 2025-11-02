//
// Created by raphael on 9/29/25.
//

#include "Modifier.hpp"

#include "Vector4.hpp"

Modifier::Modifier() : position(0, 0), size(0, 0), minSize(0, 0), anchor(LEFT, LEFT), padding(raylib::Vector4(0, 0, 0, 0)) {
}

Modifier Modifier::setSize(raylib::Vector2 size) {
    this->size = size;
    return *this;
}

Modifier Modifier::setAnchor(Anchor2 anchor) {
    this->anchor = anchor;
    return *this;
}

Modifier Modifier::setPosition(raylib::Vector2 pos) {
    this->position = pos;
    return *this;
}

Modifier Modifier::setMinimumSize(raylib::Vector2 minSize) {
    this->minSize = minSize;
    return *this;
}

Modifier Modifier::setPadding(float newPadding) {
    this->padding = raylib::Vector4(newPadding, newPadding, newPadding, newPadding);
    return *this;
}

Modifier Modifier::setPadding(float left, float top, float right, float bottom) {
    this->padding = raylib::Vector4(left, top, right, bottom);
    return *this;
}
