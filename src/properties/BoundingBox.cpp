#include "BoundingBox.hpp"

namespace property {
    BoundingBox::BoundingBox(float x, float y, float width, float height) : position(x, y), size(width, height) {

    }

    BoundingBox::BoundingBox(backend::ScreenCoordinate position, backend::RectangleSize size) : position(position), size(size) {

    }
}
