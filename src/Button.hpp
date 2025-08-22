//
// Created by raphael on 8/19/25.
//

#ifndef NATIVEUI_BUTTON_HPP
#define NATIVEUI_BUTTON_HPP
#include <functional>
#include <utility>

#include "Panel.hpp"


class Button : public Panel {
public:
    Button(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor,
           std::function<void (void)> callback) : Panel(position, size, anchor, true),
                                                  callback(std::move(callback)),
                                                  down(false) {
    }

protected:
    void update() override;

    void draw() override;

    // Is the user hovering and holding mlb ?
    bool down;

    // Function to call when the button is pressed.
    std::function<void (void)> callback;

    StyleBox hoverStyle = DEFAULT_HOVER_STYLE;

    StyleBox downStyle = DEFAULT_DOWN_STYLE;
};


#endif //NATIVEUI_BUTTON_HPP
