//
// Created by raphael on 18/10/2025.
//

#ifndef NATIVEUI_IMAGE_HPP
#define NATIVEUI_IMAGE_HPP
#include "Component.hpp"

namespace UIComponent {

    enum class imageResizeMode{
        STRETCH,
        ADJUST,
        KEEP_HEIGHT,
        KEEP_WIDTH,
    };

    /**
     * @brief Represents a texture (an image on the GPU).
     * @note It can represent any kind of rasterized content,
     * like text.
     */
    class Image : public Component{
    public:
        Image(Modifier modifier, LayoutType layout, const std::string& imagePath);

        /**
         * @brief Doesn't initialize texture itself. Used to manually initialize the texture outside.
         * @param modifier transformations properties
         * @param layout describes how a component should draw its children.
         */
        Image(Modifier modifier, LayoutType layout);
        ~Image() = default;

        raylib::Rectangle GetScreenSpaceRectangle() const override;


    protected:
        /**
         * @brief Actual content of the component
         */
        raylib::Texture texture;

        virtual void draw() override;

    private:
        imageResizeMode resizeMode;

    };
} // UIComponent

#endif //NATIVEUI_IMAGE_HPP