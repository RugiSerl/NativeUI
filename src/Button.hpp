//
// Created by raphael on 8/19/25.
//

#ifndef NATIVEUI_BUTTON_HPP
#define NATIVEUI_BUTTON_HPP
#include <functional>
#include <utility>

#include "Panel.hpp"

/**
 * Button calling a function when it is being clicked.
 */
class Button : public Panel {
public:
    /**
     * @brief constructs a new Button object.
     * @param position Position of the button.
     * @param size Size of the button.
     * @param anchor Origin of the position
     * @param callback function to call when the button is clicked.
     */
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

    // styleBox when the cursor is above the component.
    StyleBox hoverStyle = DEFAULT_HOVER_STYLE;

    // StyleBox when the user is hovering and holding mlb.
    StyleBox downStyle = DEFAULT_DOWN_STYLE;
};


#endif //NATIVEUI_BUTTON_HPP
