//
// Created by raphael on 8/22/25.
//

#include "Window.hpp"

#include <iostream>

#include "Button.hpp"

Window::Window(std::string title, Modifier modifier, TransformState availableTransform) : title(title),
                                                                                          PanelResizable(modifier, LayoutType::COLUMN, availableTransform) {
    // Hide button
    this->AddChild(
        new Button(Modifier()
                   .setAnchor(Anchor2(Anchor::RIGHT, Anchor::TOP))
                   .setSize(raylib::Vector2(20, 20))
                   .setMinimumSize(raylib::Vector2(0, 0))
                   .setPosition(raylib::Vector2(5, 5)),
                   LayoutType::ROW,
                   [this] { Hide(); })
    );


}

void Window::update() {
    PanelResizable::update();
}
