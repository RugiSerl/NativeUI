//
// Created by raphael on 11/2/25.
//

#include "Canvas.hpp"

#include "Mouse.hpp"
#include "Rectangle.hpp"

namespace UIComponent {
    Canvas::Canvas(Modifier modifier, LayoutType layout) : Image(modifier, layout), renderTexture(modifier.size.x, modifier.size.y){
        // The texture of the Image object is initialized as the texture of the renderTexture
        texture = renderTexture.GetTexture();
    }

    void Canvas::Render(std::function<void()> contentToDraw) {
        BeginTextureMode(this->renderTexture);
            contentToDraw();
        EndTextureMode();
    }

    raylib::Vector2 Canvas::GetRelativePosition(raylib::Vector2 absolutePosition) const {
        raylib::Rectangle rect = GetScreenSpaceRectangle();
        raylib::Vector2 relativePositionWithoutStretch = absolutePosition - rect.GetPosition();
        return {relativePositionWithoutStretch.x * texture.width / rect.width, relativePositionWithoutStretch.y * texture.height / rect.height};
    }

    raylib::Vector2 Canvas::GetMouseRelativePosition() const {
        return GetRelativePosition(raylib::Mouse::GetPosition());
    }

    void Canvas::draw() {
        texture.Draw(raylib::Rectangle(0, texture.height, texture.width, -texture.height), GetScreenSpaceRectangle());
    }
} // UIComponents