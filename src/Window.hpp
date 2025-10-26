//
// Created by raphael on 8/22/25.
//

#ifndef NATIVEUI_WINDOW_HPP
#define NATIVEUI_WINDOW_HPP
#include "PanelTransformable.hpp"

namespace UIComponent {
    /**
     * @brief A component used to display windows inside the main windows, handled entirely by the library.
     * It consists in a top bar with action buttons and an empty space for content.
     */
    class Window : public PanelTransformable {
    public:

        Window(std::string title, Modifier modifier, TransformState availableTransform = TransformState(true));

        ~Window() override = default;

        void AddChild(Component *child) override;

    protected:
        void update() override;


    private:
        std::string title;

        /**
         * Container of the bar at the top of the window.
         */
        Component* topBar;

        /**
         * Rest of the window.
         */
        Component* content;
    };
}

#endif //NATIVEUI_WINDOW_HPP
