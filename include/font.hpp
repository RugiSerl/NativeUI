#ifndef __FONT_HPP__
#define __FONT_HPP__

#include "vector2.hpp"
#include "external/raylib.h"
#include <string>
namespace graphic {
    class _Font {
    public:
        _Font(const std::string& path, int fontSize);
        ~_Font() = default;

        void draw(const std::string& text, const math::Vector2& position, const Color& color);
        void setSize(int fontSize);
    private:
        Font data;
        int size;
    };
}

#endif // __FONT_HPP__
