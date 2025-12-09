#include "Texture.hpp"
#include "raylib.h"

namespace backend {
    Texture::Texture(std::string filename) {
        Texture2D tex = LoadTexture(filename.c_str());
        id = tex.id;
        format = tex.format;
        height = tex.height;
        width = tex.width;
        mipmaps = tex.mipmaps;
    }
    Texture::~Texture() {
        UnloadTexture(*this);
    }

    void Texture::Draw(int x, int y, backend::Color color) {
        DrawTexture(*this, x, y, color);
    }
}
