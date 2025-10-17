//
// Created by raphael on 8/22/25.
//

#include "Window.hpp"

#include <iostream>

#include "Button.hpp"

Window::Window(std::string title, Modifier modifier, TransformState availableTransform) : title(title),
                                                                                          PanelResizable(modifier, LayoutType::COLUMN, availableTransform) {
    // TODO fix column behaving as a row and vice versa in that context.
    topBar = new Component(Modifier()
                       .setAnchor(Anchor2(Anchor::FILL, Anchor::TOP))
                       .setSize(raylib::Vector2(0, 40))
                       .setPosition(raylib::Vector2(0, 0)),
                       LayoutType::COLUMN
    );
    topBar->MakePassive();

    // Hide button
    topBar->AddChild(
        new Button(Modifier()
                   .setAnchor(Anchor2(Anchor::RIGHT, Anchor::FILL))
                   .setSize(raylib::Vector2(40, 40))
                   .setMinimumSize(raylib::Vector2(20, 20))
                   .setPosition(raylib::Vector2(40, 0)),
                   LayoutType::ROW,
                   [this] { Hide(); })
    );
    // Hide button
    topBar->AddChild(
        new Button(Modifier()
                   .setAnchor(Anchor2(Anchor::RIGHT, Anchor::FILL))
                   .setSize(raylib::Vector2(40, 40))
                   .setMinimumSize(raylib::Vector2(20, 20))
                   .setPosition(raylib::Vector2(0, 0)),
                   LayoutType::ROW,
                   [this] { Hide(); })
    );

    this->AddChild(topBar);


}

void Window::update() {
    PanelResizable::update();
}
