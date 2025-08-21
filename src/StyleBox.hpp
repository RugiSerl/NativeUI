//
// Created by raphael on 8/16/25.
//

#ifndef NATIVEUI_STYLEBOX_HPP
#define NATIVEUI_STYLEBOX_HPP
#include "../include/raylib-cpp.hpp"

/**
 * Describe parameters for a styleBox
 */
class StyleBox {
public:
    Color fillColor;
    Color borderColor;
    float borderWidth;
    float borderRadius;

    /**
     * @brief Creates a styleBox object.
     * @param fillColor Color inside the rectangle.
     * @param borderColor Color of the border of the box.
     * @param borderWidth Thickness of the border.
     * @param borderRadius Radius of the rounded corner.
     */
    StyleBox(Color fillColor, Color borderColor, float borderWidth, float borderRadius) : fillColor(fillColor), borderColor(borderColor), borderWidth(borderWidth), borderRadius(borderRadius) {};

    /**
     * Render the styleBox.
     * @param rect Size on screen of the rectangle to draw.
     * @param scissorRect Rect delimitating the surface to draw the styleBox.
     */
    void draw(raylib::Rectangle rect, raylib::Rectangle scissorRect) const;
};


#endif //NATIVEUI_STYLEBOX_HPP
