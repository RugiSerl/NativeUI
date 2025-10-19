//
// Created by raphael on 18/10/2025.
//

#include "Image.hpp"

#include "Component.hpp"

namespace UIComponent {
    Image::Image(Modifier modifier, LayoutType layout, const std::string& imagePath) : Component(modifier, layout), texture(imagePath) {
    }


    void Image::draw() {
        texture.Draw(raylib::Rectangle(0, 0, texture.width, texture.height), GetScreenSpaceRectangle());
        
    }
    
} // UIComponent