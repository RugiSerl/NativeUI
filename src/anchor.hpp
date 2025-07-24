#ifndef __ANCHOR_H__
#define __ANCHOR_H__
#include "raylib-cpp.hpp"

enum Anchor {
    CENTER,
    FILL,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

class Anchor2 {
    public:
        Anchor horizontal, vertical;
};

raylib::Rectangle GetScreenBoundingbox();

/**
 * Get the screen coordinates of the rectangle
 */
raylib::Rectangle GetAnchoredRect(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle BoundingBox = GetScreenBoundingbox());


#endif