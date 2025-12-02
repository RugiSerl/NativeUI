//
// Created by raphael on 11/2/25.
//

#include "Canvas.hpp"

#include "Mouse.hpp"
#include "Rectangle.hpp"

namespace UIComponent {
    Canvas::Canvas(Modifier modifier, LayoutType layout) : Image(modifier, layout), renderTexture(modifier.size.x, modifier.size.y){
        
    }

    void Canvas::Render(std::function<void()> contentToDraw) {
        renderTexture.BeginMode();
            contentToDraw();
        renderTexture.EndMode();
    }

    math::Vector2 Canvas::GetRelativePosition(math::Vector2 absolutePosition) const {
        math::Rectangle rect = GetScreenSpaceRectangle();
        return {(absolutePosition.x - rect.x) * renderTexture.GetWidth() / rect.width, (absolutePosition.y - rect.y) * renderTexture.GetHeight() / rect.height};
    }

    math::Vector2 Canvas::GetMouseRelativePosition() const {
        return GetRelativePosition(raylib::Mouse::GetPosition());
    }

    void Canvas::draw() {
        renderTexture.Draw(math::Rectangle(0, renderTexture.GetHeight(), renderTexture.GetWidth(), -renderTexture.GetHeight()), GetScreenSpaceRectangle());
    }

    graphic::Texture& Canvas::GetTexture() {
        return renderTexture;
    }
} // UIComponents