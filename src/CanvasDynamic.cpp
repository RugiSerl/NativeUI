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
            // Making a temporary copy of our content.
            raylib::RenderTexture tmp = std::move(renderTexture);
            renderTexture = raylib::RenderTexture(static_cast<int>(screenSpaceSize.x), static_cast<int>(screenSpaceSize.y));

            // Drawing the old content onto the new one to avoid artifacts from random memory in the GPU (since
            // the renderTexture was initialized without any content).
            BeginTextureMode(renderTexture);
                ClearBackground(BLACK);
                DrawTextureRec(tmp.texture, raylib::Rectangle(0, texture.height, texture.width, -texture.height), raylib::Vector2(0, 0), WHITE);
            EndTextureMode();

            // Finally unload that copy to free space.
            tmp.Unload();
            texture = renderTexture.GetTexture();
        }
    }
} // UIComponent