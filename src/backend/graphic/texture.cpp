#include "texture.hpp"
#include "RenderTexture.hpp"
#include "raylib.h"

namespace graphic {
    void Texture::Draw(math::Rectangle sourceRect, math::Rectangle destRect) const {
        texture.Draw(sourceRect.ToRaylibRectangle(), destRect.ToRaylibRectangle());
    }
    void Texture::Draw(math::Rectangle sourceRect, math::Vector2 position) const {
        DrawTextureRec(texture, sourceRect.ToRaylibRectangle(), position.ToRaylibVector2(), WHITE);
    }


    void Texture::Unload() {
        texture.Unload();
    }

    void Texture::SetFilter(int filter) {
        texture.SetFilter(filter);
    }

    int Texture::GetWidth() const {
        return texture.width;
    }
    int Texture::GetHeight() const {
        return texture.height;
    }

    void RenderTexture::BeginMode() {
        content.BeginMode();
    }

    void RenderTexture::EndMode() {
        content.EndMode();
    }

    void RenderTexture::Resize(int newWidth, int newHeight) {
        // Making a temporary copy of our content.
        raylib::RenderTexture tmp = std::move(content);
        content = raylib::RenderTexture(newWidth, newHeight);

        // Drawing the old content onto the new one to avoid artifacts from random memory in the GPU (since
        // the renderTexture was initialized without any content).
        BeginTextureMode(content);
            ClearBackground(BLACK); // clean previous residues.
            DrawTextureRec(tmp.texture, raylib::Rectangle(0, texture.height, texture.width, -texture.height), raylib::Vector2(0, 0), WHITE);
        EndTextureMode();

        // Finally unload that copy to free space.
        tmp.Unload();
        texture = content.GetTexture();
    }
}