//
// Created by raphael on 18/10/2025.
//

#ifndef NATIVEUI_IMAGE_HPP
#define NATIVEUI_IMAGE_HPP
#include "Component.hpp"

namespace UIComponent {
    /**
     * @brief Represents a texture (an image on the GPU).
     * @note It can represent any kind of rasterized content,
     * like text.
     */
    class Image : public Component{
    public:
        Image(Modifier modifier, LayoutType layout);
        ~Image() = default;


    };
} // UIComponent

#endif //NATIVEUI_IMAGE_HPP