#pragma once
#include "raylib.h"
namespace backend {
    /**
     * Wrapper for color object from raylib. Describes a color with RGBA, each ranging from 0 to 255.
     */
    class Color : public ::Color {
    public:
        /**
         * Defaults as black with full opacity (0, 0, 0, 255)
         */
        Color();
        Color(int r, int g, int b, int a);
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    };
}
