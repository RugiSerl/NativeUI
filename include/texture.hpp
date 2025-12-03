#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "external/RenderTexture.hpp"
#include "external/Texture.hpp"
#include "rectangle.hpp"
#include "external/TextureUnmanaged.hpp"
#include "external/raylib.h"
#include <utility>

namespace graphic {

    class Texture {
    public:
        Texture(const std::string& imagePath) : texture(imagePath) {};
        Texture() : texture() {};
        ~Texture() {texture.Unload();};
        void Unload();
    
        void Draw(math::Rectangle sourceRect, math::Rectangle destRect) const;
        void Draw(math::Rectangle sourceRect, math::Vector2 position = math::Vector2(0, 0)) const;
        void SetFilter(int);

        int GetWidth() const;
        int GetHeight() const;

    protected:
        raylib::TextureUnmanaged texture;
    };

    class RenderTexture : public Texture {
    public:
        RenderTexture(int width, int height) : content(width, height) {
            texture = content.texture;
        };
        void BeginMode();
        void EndMode();

        void Resize(int newWidth, int newHeight);        

        // be careful with this one. Doesn't copy the texture
        Texture& GetTexture();
    private:
        raylib::RenderTexture2D content;
    };
}

#endif //__TEXTURE_HPP__