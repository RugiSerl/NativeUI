#pragma once
#include "raylib.h"
namespace backend {
    class Color : public ::Color {
    public:
        Color();
        Color(int r, int g, int b, int a);
    };
}
