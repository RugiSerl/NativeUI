//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UIPANEL_HPP
#define NATIVEUI_UIPANEL_HPP
#include "Component.hpp"
#include "StyleBox.hpp"

class Panel : public Component {
public:
    Panel(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor, StyleBox style) : Component(position, size, anchor), style(style) {};

    ~Panel() override = default;

    virtual void update() override;

    virtual void draw() override;

private:
    StyleBox style;
};


#endif //NATIVEUI_UIPANEL_HPP
