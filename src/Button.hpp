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
    Button(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor, std::function<void (void)> callback,
           StyleBox style = DEFAULT_STYLE,
           StyleBox selectedStyle = DEFAULT_SELECTED_STYLE, StyleBox hoverStyle = DEFAULT_HOVER_STYLE,
           StyleBox downStyle = DEFAULT_DOWN_STYLE) : Panel(position, size, anchor, style, selectedStyle, true),
                                                      hoverStyle(hoverStyle), downStyle(downStyle), callback(std::move(callback)),
                                                      down(false) {
    }
    ;

protected:
    void update() override;

    void draw() override;

private:
    bool down;
    std::function<void (void)> callback;
    StyleBox hoverStyle;
    StyleBox downStyle;
};


#endif //NATIVEUI_BUTTON_HPP
