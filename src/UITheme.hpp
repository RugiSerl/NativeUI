#ifndef __UITHEME_H__
#define __UITHEME_H__

#include "UIStylebox.hpp"
#include "raylib-cpp.hpp"

#define DEFAULT_PANEL_STYLEBOX UIStylebox(2, 3, WHITE, LIGHTGRAY)
#define DEFAULT_SELECTED_STYLEBOX UIStylebox(2, 2, Color{0, 0, 0, 0}, Color{0, 0, 0, 128}, 1)
#define DEFAULT_HOVER_STYLEBOX UIStylebox(2, 3, WHITE, GRAY)
#define DEFAULT_BUTTON_DOWN_STYLEBOX UIStylebox(2, 3, WHITE, BLACK)





#endif // !__UITHEME_H__