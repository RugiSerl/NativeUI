#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "rectangle.hpp"
#include "external/raylib.h"
#include <string>
#include <utility>

namespace graphic {

    class Texture {
    public:
        Texture(const std::string& imagePath) {
            texture = LoadTexture(imagePath.c_str());
        };
        Texture() : texture() {};
        ~Texture() {UnloadTexture(texture);};
        void Unload();
    
        void Draw(math::Rectangle sourceRect, math::Rectangle destRect) const;
        void Draw(math::Rectangle sourceRect, math::Vector2 position = math::Vector2(0, 0)) const;
        void SetFilter(int);

        int GetWidth() const;
        int GetHeight() const;

    protected:
         texture;
    };

    class _RenderTexture : public Texture {
    public:
        _RenderTexture(int width, int height)  {
            content = LoadRenderTexture(width, height);
            texture = content.texture;
        };
        void BeginMode();
        void EndMode();

        void Resize(int newWidth, int newHeight);        

        // be careful with this one. Doesn't copy the texture
        Texture& GetTexture();
    private:
        RenderTexture2D content;
    };
}

#endif //__TEXTURE_HPP__