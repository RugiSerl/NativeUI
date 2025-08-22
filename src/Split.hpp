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

class Split : public Panel {
public:

    Split(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor,
                   StyleBox style = DEFAULT_STYLE,
                   StyleBox selectedStyle = DEFAULT_SELECTED_STYLE);

    ~Split() override = default;


    raylib::Rectangle GetSplitRectangle(int side);

protected:
    splitType type;

    float barOffset;
};


#endif //NATIVEUI_SPLIT_HPP
