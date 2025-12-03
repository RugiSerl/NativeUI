#ifndef __ANCHOR_H__
#define __ANCHOR_H__
#include "external/raylib-cpp.hpp"
#include "rectangle.hpp"


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
 * @return math::Rectangle
 */
math::Rectangle GetScreenBoundingbox();


/**
 * @brief Get the rect in screen coordinates and from top left
 *
 * @param rect relative rectangle
 * @param anchor
 * @param boundingBox bound constraint
 * @return math::Rectangle objective rectangle
 */
math::Rectangle GetAnchoredRect(math::Rectangle rect, Anchor2 anchor, math::Rectangle boundingBox = GetScreenBoundingbox());


#endif
