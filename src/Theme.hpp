//
// Created by raphael on 8/16/25.
//

#ifndef NATIVEUI_THEME_HPP
#define NATIVEUI_THEME_HPP
#include "StyleBox.hpp"

#define DEFAULT_STYLE StyleBox(WHITE, LIGHTGRAY, 2.0f, 3.0f)
#define DEFAULT_SELECTED_STYLE StyleBox(Color{0, 0, 0, 0}, Color{0, 0, 0, 128}, 1.0f, 1.0f)
#define DEFAULT_HOVER_STYLE StyleBox(Color{255, 255, 255, 120}, Color{0, 0, 0, 0}, 0.0, 1.0f)
#define DEFAULT_DOWN_STYLE StyleBox(WHITE, BLACK, 2.0f, 3.0f)

#endif //NATIVEUI_THEME_HPP