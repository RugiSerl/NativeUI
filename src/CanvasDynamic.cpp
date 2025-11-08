//
// Created by raphael on 11/8/25.
//

#include "CanvasDynamic.hpp"

#include <iostream>

namespace UIComponent {
    CanvasDynamic::CanvasDynamic(Modifier modifier, LayoutType layout) : Canvas(modifier, layout) {
    }

    void CanvasDynamic::update() {
        Canvas::update();
        Vector2 screenSpaceSize = GetScreenSpaceRectangle().GetSize();
        if (screenSpaceSize.x != texture.width || screenSpaceSize.y != texture.height) {
            raylib::RenderTexture tmp = std::move(renderTexture);
            renderTexture = raylib::RenderTexture(static_cast<int>(screenSpaceSize.x), static_cast<int>(screenSpaceSize.y));
            tmp.Unload();
            texture = renderTexture.GetTexture();
        }
    }
} // UIComponent