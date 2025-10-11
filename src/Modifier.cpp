//
// Created by raphael on 9/29/25.
//

#include "Modifier.hpp"

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

