#include "font.hpp"

namespace graphic {
    Font::Font(const std::string& path, int fontSize) : data(path, fontSize), size(fontSize) {
    }

    void Font::draw(const std::string& text, const math::Vector2& position, const Color& color) {
        data.DrawText(text, position.ToRaylibVector2(), size, 0, color);
    }
}
