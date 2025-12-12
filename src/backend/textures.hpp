#pragma once
#include "colors.hpp"
#include "external/raylib.h"
#include <string>
namespace backend {
    /**
     * @brief Simple wrapper around raylib's Texture2D
     *
     */
    class Texture : public ::Texture2D {
        public:
            Texture(std::string filename);
            ~Texture();
            void Draw(int x, int y, backend::Color color);

    };
}
