//
// Created by raphael on 8/22/25.
//

#ifndef NATIVEUI_SPLIT_HPP
#define NATIVEUI_SPLIT_HPP
#include "Panel.hpp"

enum class splitType {
    VERTICAL_SPLIT,
    HORIZONTAL_SPLIT,
};

class Split : public Component {
public:

    Split(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor);

    ~Split() override = default;

    raylib::Rectangle GetSplitRectangle(int side);

protected:
    splitType type;

    float barOffset;
};


#endif //NATIVEUI_SPLIT_HPP
