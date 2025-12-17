#include "ScreenRectangle.hpp"

namespace property {
    ScreenRectangle::ScreenRectangle(float x, float y, float width, float height) : position(x, y), size(width, height) {

    }

    ScreenRectangle::ScreenRectangle(backend::ScreenCoordinate position, backend::RectangleSize size) : position(position), size(size) {

    }
}
