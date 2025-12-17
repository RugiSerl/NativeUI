#include "ScreenRectangle.hpp"

namespace coordinates {
    ScreenRectangle::ScreenRectangle(float x, float y, float width, float height) : position(x, y), size(width, height) {

    }

    ScreenRectangle::ScreenRectangle(ScreenCoordinate position, backend::RectangleSize size) : position(position), size(size) {

    }
}
