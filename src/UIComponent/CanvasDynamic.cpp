//
// Created by raphael on 11/8/25.
//

#include "CanvasDynamic.hpp"
#include "raylib.h"

#include <iostream>

namespace UIComponent {
    CanvasDynamic::CanvasDynamic(Modifier modifier, LayoutType layout) : Canvas(modifier, layout) {
    }

    void CanvasDynamic::update() {
        Canvas::update();
        math::Vector2 screenSpaceSize = GetScreenSpaceRectangle().GetSize();
        if (screenSpaceSize.x > 0 && screenSpaceSize.y > 0 && (screenSpaceSize.x != renderTexture.GetWidth() || screenSpaceSize.y != renderTexture.GetHeight())) {
            renderTexture.Resize(screenSpaceSize.x, screenSpaceSize.y);
        }
    }
} // UIComponent