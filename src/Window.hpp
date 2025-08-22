//
// Created by raphael on 8/22/25.
//

#ifndef NATIVEUI_WINDOW_HPP
#define NATIVEUI_WINDOW_HPP
#include "PanelResizable.hpp"


class Window : public PanelResizable {
public:

    Window();

    ~Window() override = default;
};


#endif //NATIVEUI_WINDOW_HPP
