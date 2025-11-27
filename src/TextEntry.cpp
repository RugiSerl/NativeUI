#include "TextEntry.hpp"
#include "Color.hpp"
#include "Functions.hpp"
#include "Keyboard.hpp"
#include "Layout.hpp"
#include "Panel.hpp"
#include "Rectangle.hpp"
#include "raylib.h"
#include <iostream>

namespace UIComponent {
    TextEntry::TextEntry(Modifier modifier, LayoutType layout): Panel(modifier, layout, true), text() {
    }

    void TextEntry::update() {
        Panel::update();
        if (selected) {
            if (char letter = raylib::Keyboard::GetCharPressed()) { // making sure that letter != 0
                text += letter;
            }
        }
    }

    void TextEntry::draw() {
        Panel::draw();
        raylib::Rectangle rect = GetScreenSpaceRectangle();
        raylib::DrawText(text, rect.x, rect.y, 10, BLACK);
    }
}