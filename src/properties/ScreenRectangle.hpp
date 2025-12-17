#pragma once
#include "../backend/coordinates.hpp"
#include "../backend/rectangles.hpp"

namespace property {
    class ScreenRectangle {
    public:
        ScreenRectangle(float x, float y, float width, float height);
        ScreenRectangle(backend::ScreenCoordinate position, backend::RectangleSize size);

        backend::ScreenCoordinate position;
        backend::RectangleSize size;
    };
}
