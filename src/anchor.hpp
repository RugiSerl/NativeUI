#ifndef __ANCHOR_H__
#define __ANCHOR_H__
#include "raylib-cpp.hpp"


/**
 * @brief points on the screen to set the position from
 *
 */
enum Anchor {
    CENTER,
    FILL,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};


/**
 * @brief Set of Two Anchors for 2d positioning
 *
 */
class Anchor2 {
public:
    Anchor2(Anchor horizontal, Anchor vertical) : horizontal(horizontal), vertical(vertical) {
    }

    Anchor horizontal, vertical;
};


/**
 * @brief Get the Screen Boundingbox object
 *
 * @return raylib::Rectangle
 */
raylib::Rectangle GetScreenBoundingbox();


/**
 * @brief Get the rect in screen coordinates and from top left
 *
 * @param rect relative rectangle
 * @param anchor
 * @param boundingBox bound constraint
 * @return raylib::Rectangle objective rectangle
 */
raylib::Rectangle GetAnchoredRect(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox = GetScreenBoundingbox());


#endif
