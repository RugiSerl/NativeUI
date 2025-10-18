//
// Created by raphael on 8/19/25.
//

#ifndef NATIVEUI_BUTTON_HPP
#define NATIVEUI_BUTTON_HPP
#include <functional>
#include <utility>

#include "Panel.hpp"

namespace UIComponent {
    /**
     * Button calling a function when it is being clicked.
     */
    class Button : public Panel {
    public:
        /**
         * @brief constructs a new Button object.
         * @param modifier transformations properties.
         * @param callback function to call when the button is clicked.
         * @param layout describes how a component should draw its children
         */
        Button(Modifier modifier, LayoutType layout, std::function<void ()> callback);

    protected:
        void update() override;

        void draw() override;

        // Is the user hovering and holding mlb ?
        bool down;

        // Function to call when the button is pressed.
        std::function<void ()> callback;

        // styleBox when the cursor is above the component.
        StyleBox hoverStyle = DEFAULT_HOVER_STYLE;

        // StyleBox when the user is hovering and holding mlb.
        StyleBox downStyle = DEFAULT_DOWN_STYLE;
    };

}


#endif //NATIVEUI_BUTTON_HPP
