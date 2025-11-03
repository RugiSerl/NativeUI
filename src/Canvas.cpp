//
// Created by raphael on 11/2/25.
//

#include "Canvas.hpp"

#include "Rectangle.hpp"

namespace UIComponent {
    Canvas::Canvas(Modifier modifier, LayoutType layout) : Image(modifier, layout), renderTexture(modifier.size.x, modifier.size.y){
        // The texture of the Image object is initialized as the texture of the renderTexture
        texture = renderTexture.GetTexture();
    }

    void Canvas::Render(std::function<void()> contentToDraw) const {
        BeginTextureMode(this->renderTexture);
            contentToDraw();
        EndTextureMode();
    }

    void Canvas::draw() {
        texture.Draw(raylib::Rectangle(0, texture.height, texture.width, -texture.height), GetScreenSpaceRectangle());
    }
} // UIComponents