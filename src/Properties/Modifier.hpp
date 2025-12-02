//
// Created by raphael on 9/29/25.
//

#ifndef NATIVEUI_MODIFIER_HPP
#define NATIVEUI_MODIFIER_HPP
#include "Anchor.hpp"
#include "Vector2.hpp"

/**
 * @brief Gathers different aspects of the layout to avoid boilerplate arguments in Component initializers.
 */
class Modifier {
public:
    // Set with default values. use Setters to change the values.
    Modifier();

    // Setters of the class. Returns itself to chain setter.
    Modifier setSize(math::Vector2 size);

    Modifier setPosition(math::Vector2 pos);

    Modifier setAnchor(Anchor2 anchor);

    Modifier setMinimumSize(math::Vector2 minSize);

    Modifier setPadding(float newPadding);

    Modifier setPadding(float left, float top, float right, float bottom);


    math::Vector2 position;
    math::Vector2 size;
    math::Vector2 minSize;
    Anchor2 anchor;
    raylib::Vector4 padding;
};


#endif //NATIVEUI_MODIFIER_HPP
