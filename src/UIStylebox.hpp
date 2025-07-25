#ifndef __UISTYLEBOX_H__
#define __UISTYLEBOX_H__
#include "raylib-cpp.hpp"
#include "anchor.hpp"

class UIStylebox {
public:
    /**
     * Defines graphic properties of a rectangle
     * @param borderThickness thickness of the edges
     * @param cornerRadius amount of roundness on the corners
     * @param fillColor color inside of the rectangle
     * @param borderColor color on the edges of the rectangle
     * @param innerOffset offset of the inner rect
     * @param shadowDistance distance to the rectangle's drop shadow (doesn't matter if <=0)
     */
    UIStylebox(float borderThickness, float cornerRadius, Color fillColor, Color borderColor, float innerOffset = 0, float shadowDistance = 0);
    float borderThickness, cornerRadius;
    Color fillColor, borderColor;
    float innerOffset;
    float shadowDistance;
    Texture2D Image; // optionnal
    void draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox);
    void draw(raylib::Rectangle rect);
};


#endif