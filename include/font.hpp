#ifndef __FONT_HPP__
#define __FONT_HPP__

#include "Font.hpp"
#include "vector2.hpp"
#include <string>
namespace graphic {
    class Font {
    public:
        Font(const std::string& path, int fontSize);
        ~Font() = default;

        void draw(const std::string& text, const math::Vector2& position, const Color& color);
        void setSize(int fontSize);
    private:
        raylib::Font data;
        int size;
    };
}

#endif // __FONT_HPP__
