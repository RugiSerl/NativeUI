//
// Created by raphael on 11/8/25.
//

#ifndef NATIVEUI_CANVASDYNAMIC_HPP
#define NATIVEUI_CANVASDYNAMIC_HPP
#include "Canvas.hpp"

namespace UIComponent {
    /**
     * @brief Canvas that reloads whenever it is being resized.
     */
    class CanvasDynamic : public Canvas {
    public:
        CanvasDynamic(Modifier modifier, LayoutType layout);

    protected:
        void update() override;

    };
} // UIComponent

#endif //NATIVEUI_CANVASDYNAMIC_HPP