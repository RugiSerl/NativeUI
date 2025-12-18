#pragma once
#include "../shape/RectangleRounded.hpp"

namespace style {
    class StylizedRectangleRounded : public shape::RectangleRounded  {
    public:
        StylizedRectangleRounded(coordinates::RelativeRectangle rectangle, float cornerRadius);
    };
}
