//
// Created by raphael on 9/29/25.
//

#ifndef NATIVEUI_MODIFIER_HPP
#define NATIVEUI_MODIFIER_HPP
#include "anchor.hpp"
#include "../include/Vector2.hpp"

/**
 * @brief Gathers different aspects of the layout to avoid boilerplate arguments in Component initializers.
 */
class Modifier {
public:
    // Set with default values. use Setters to change the values.
    Modifier() : position(0, 0), size(0, 0), anchor(LEFT, LEFT){};

    // Setters of the class. Returns itself to chain setter.
    Modifier setSize(raylib::Vector2 size);
    Modifier setPosition(raylib::Vector2 pos);
    Modifier setAnchor(Anchor2 anchor);


    raylib::Vector2 position;
    raylib::Vector2 size;
    Anchor2 anchor;
};


#endif //NATIVEUI_MODIFIER_HPP