//
// Created by raphael on 8/16/25.
//

#ifndef NATIVEUI_STYLEBOX_HPP
#define NATIVEUI_STYLEBOX_HPP
#include "../include/raylib-cpp.hpp"


class StyleBox {
public:
    Color fillColor;
    Color borderColor;
    float borderWidth;
    float borderRadius;

    StyleBox(Color fillColor, Color borderColor, float borderWidth, float borderRadius) : fillColor(fillColor), borderColor(borderColor), borderWidth(borderWidth), borderRadius(borderRadius) {};

    void draw(raylib::Rectangle rect, raylib::Rectangle scissorRect) const;
};


#endif //NATIVEUI_STYLEBOX_HPP
