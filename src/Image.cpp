//
// Created by raphael on 18/10/2025.
//

#include "Image.hpp"

#include "Component.hpp"

namespace UIComponent {
    Image::Image(Modifier modifier, LayoutType layout, const std::string& imagePath) : Component(modifier, layout) {
        // texture.Load(imagePath);

    }

    void Image::draw() {
        Component::draw();

    }
} // UIComponent