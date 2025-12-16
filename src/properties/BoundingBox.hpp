#pragma once
#include "../backend/coordinates.hpp"
#include "../backend/rectangles.hpp"

namespace property {
    class BoundingBox {
    public:
        BoundingBox(float x, float y, float width, float height);
        BoundingBox(backend::ScreenCoordinate position, backend::RectangleSize size);

        backend::ScreenCoordinate position;
        backend::RectangleSize size;
    };
}
