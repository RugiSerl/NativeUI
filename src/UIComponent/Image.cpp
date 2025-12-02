//
// Created by raphael on 18/10/2025.
//

#include "Image.hpp"

#include "Component.hpp"
#include "../math/rectangle.hpp"
#include "raylib.h"

namespace UIComponent {
    Image::Image(Modifier modifier, LayoutType layout, const std::string& imagePath) : Component(modifier, layout), texture(imagePath) {
        texture.SetFilter(RL_TEXTURE_FILTER_BILINEAR);

    }

    Image::Image(Modifier modifier, LayoutType layout) : Component(modifier, layout) {

    }

    math::Rectangle Image::GetScreenSpaceRectangle() const {
        math::Rectangle rect = Component::GetScreenSpaceRectangle();
        // const float imgRatio = ;
        switch (resizeMode) {
            case imageResizeMode::STRETCH:
                break; // already done
            case imageResizeMode::ADJUST:
                // TODO


            case imageResizeMode::KEEP_HEIGHT:
                rect = math::Rectangle();
                break;

            default:
                break; // already done
        }

        return rect;
    }

    graphic::Texture& Image::GetTexture() {
        return texture;
    }


    void Image::draw() {
        GetTexture().Draw(math::Rectangle(0, 0, texture.GetWidth(), texture.GetHeight()), GetScreenSpaceRectangle());
    }
    
} // UIComponent