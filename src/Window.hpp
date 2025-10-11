//
// Created by raphael on 8/22/25.
//

#ifndef NATIVEUI_WINDOW_HPP
#define NATIVEUI_WINDOW_HPP
#include "PanelResizable.hpp"


class Window : public PanelResizable {
public:

    Window(std::string title, Modifier modifier, TransformState availableTransform = TransformState(true));

    ~Window() override = default;

protected:
    void update() override;


private:
    std::string title;
};


#endif //NATIVEUI_WINDOW_HPP
