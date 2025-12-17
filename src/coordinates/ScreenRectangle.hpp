#pragma once
#include "../backend/rectangles.hpp"
#include "ScreenCoordinate.hpp"

namespace coordinates {
    class ScreenRectangle {
    public:
        ScreenRectangle(float x, float y, float width, float height);
        ScreenRectangle(ScreenCoordinate position, backend::RectangleSize size);

        ScreenCoordinate position;
        backend::RectangleSize size;
    };
}
