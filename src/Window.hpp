//
// Created by raphael on 8/22/25.
//

#ifndef NATIVEUI_WINDOW_HPP
#define NATIVEUI_WINDOW_HPP
#include "PanelTransformable.hpp"


class Window : public PanelTransformable {
public:

    Window(std::string title, Modifier modifier, TransformState availableTransform = TransformState(true));

    ~Window() override = default;

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
    Component* Content;
};


#endif //NATIVEUI_WINDOW_HPP
