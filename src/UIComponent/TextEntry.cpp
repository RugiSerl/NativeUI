#include "TextEntry.hpp"
#include "Functions.hpp"
#include "Layout.hpp"
#include "Panel.hpp"
#include "font.hpp"
#include "input.hpp"
#include "raylib.h"

namespace UIComponent {
    TextEntry::TextEntry(Modifier modifier, LayoutType layout, graphic::Font* font): Panel(modifier, layout, true), text(), font(font) {
    }

    void TextEntry::update() {
        Panel::update();
        if (selected) {
            if (char letter = input::GetKeyChar()) { // making sure that letter != 0
                text += letter;
            }
        }
    }

    void TextEntry::draw() {
        Panel::draw();
        math::Rectangle rect = GetScreenSpaceRectangle();
        font->draw(text, rect.GetPosition(), BLACK);
    }
}
