//
// Created by raphael on 8/22/25.
//

#include "Split.hpp"

raylib::Rectangle Split::GetSplitRectangle(int side) {

    raylib::Rectangle anchoredRect = GetScreenSpaceRectangle();

    raylib::Rectangle firstSideRect;
    raylib::Rectangle secondSideRect;

    if (type == splitType::VERTICAL_SPLIT) {
        firstSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, anchoredRect.width, barOffset);
        secondSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y + barOffset, anchoredRect.width, anchoredRect.height - barOffset);

    } else {
        firstSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, barOffset, anchoredRect.height);
        secondSideRect = raylib::Rectangle( anchoredRect.x + barOffset, anchoredRect.y, anchoredRect.width - barOffset, anchoredRect.height);
    }

    return (side == 0) ? firstSideRect : secondSideRect;
}