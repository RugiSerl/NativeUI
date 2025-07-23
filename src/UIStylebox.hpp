#ifndef __UISTYLEBOX_H__
#define __UISTYLEBOX_H__
#include "raylib-cpp.hpp"
#include "anchor.hpp"

class UIStylebox {
    public:
        UIStylebox(float borderSize, float edgeRadius, Color fillColor, Color borderColor);
        float borderSize, edgeRadius;
        Color fillColor, borderColor;
        Texture2D Image; // optionnal
        void draw(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox);
};


#endif