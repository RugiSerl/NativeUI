//
// Created by raphael on 18/10/2025.
//

#include "Image.hpp"

#include "Component.hpp"
#include "utils.hpp"

namespace UIComponent {
    Image::Image(Modifier modifier, LayoutType layout, const std::string& imagePath) : Component(modifier, layout), texture(imagePath) {
        texture.SetFilter(RL_TEXTURE_FILTER_BILINEAR);

    }

    Image::Image(Modifier modifier, LayoutType layout) : Component(modifier, layout) {

    }

    raylib::Rectangle Image::GetScreenSpaceRectangle() const {
        raylib::Rectangle rect = Component::GetScreenSpaceRectangle();
        const float imgRatio = texture.width/texture.height;
        switch (resizeMode) {
            case imageResizeMode::STRETCH:
                break; // already done
            case imageResizeMode::ADJUST:
                // TODO


            case imageResizeMode::KEEP_HEIGHT:
                rect = raylib::Rectangle();
                break;

            default:
                break; // already done
        }

        return rect;
    }


    void Image::draw() {
        texture.Draw(raylib::Rectangle(0, 0, texture.width, texture.height), GetScreenSpaceRectangle());
    }
    
} // UIComponent