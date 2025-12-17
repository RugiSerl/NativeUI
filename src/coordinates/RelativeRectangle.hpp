#pragma once

#include "ScreenCoordinate.hpp"
#include "ScreenRectangle.hpp"
#include "RelativeCoordinate.hpp"
#include "../backend/rectangles.hpp"
namespace coordinates {
    class RelativeRectangle {
    public:
        RelativeCoordinate position;
        backend::RectangleSize size;

        /**
         * Constructors
         */
        RelativeRectangle(float x, float y, float width, float height, Anchor anchor);
        RelativeRectangle(RelativeCoordinate position, backend::RectangleSize size);


        /**
         * Get the position of the shape after applying custom anchor. So now in screen coordinates.
         */
        ScreenRectangle GetScreenRectangle(ScreenRectangle containing) const;

        /**
         * Shortcut for GetScreenRectangle().position.
         */
        ScreenCoordinate GetScreenCoordinates(ScreenRectangle containing) const;
    };
}
