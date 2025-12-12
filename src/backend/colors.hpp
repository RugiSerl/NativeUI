#pragma once
#include "raylib.h"
namespace backend {
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
