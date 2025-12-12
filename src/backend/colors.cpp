#include "colors.hpp"
#include "raylib.h"

namespace backend {
    Color::Color() : ::Color{0, 0, 0, 255} {

    }

    Color::Color(int r, int g, int b, int a) : ::Color{static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), static_cast<unsigned char>(a)} {

    }

    Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : ::Color{r, g, b, a} {

    }
}
