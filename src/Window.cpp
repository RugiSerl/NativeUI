//
// Created by raphael on 8/22/25.
//

#include "Window.hpp"

#include <iostream>

#include "Button.hpp"
namespace UIComponent {
    Window::Window(std::string title, Modifier modifier, TransformState availableTransform) : title(title),
                                                                                              PanelTransformable(modifier, LayoutType::COLUMN, availableTransform) {
        topBar = new Panel(Modifier()
                           .setAnchor(Anchor2(Anchor::FILL, Anchor::TOP))
                           .setSize(raylib::Vector2(0, 40))
                           .setPosition(raylib::Vector2(0, 0)),
                           LayoutType::ROW
        );

        // Hide button
        topBar->AddChild(
            new Button(Modifier()
                       .setAnchor(Anchor2(Anchor::RIGHT, Anchor::FILL))
                       .setSize(raylib::Vector2(40, 40))
                       .setMinimumSize(raylib::Vector2(20, 20))
                       .setPosition(raylib::Vector2(40, 0))
                       .setPadding(3),
                       LayoutType::ROW,
                       [this] { Hide(); })
        );
        // Hide button
        // TODO: Change this button to give it a more appropriate function.
        topBar->AddChild(
            new Button(Modifier()
                       .setAnchor(Anchor2(Anchor::RIGHT, Anchor::FILL))
                       .setSize(raylib::Vector2(40, 40))
                       .setMinimumSize(raylib::Vector2(20, 20))
                       .setPosition(raylib::Vector2(0, 0))
                       .setPadding(3),
                       LayoutType::ROW,
                       [this] { Hide(); })
        );


        content = new Component(
               Modifier()
               .setAnchor(Anchor2(Anchor::FILL, Anchor::FILL)),
               LayoutType::NONE);

        topBar->MakePassive();
        content->MakePassive();

        Component::AddChild(topBar);
        Component::AddChild(content);
    }

    void Window::AddChild(Component *child) {
        this->content->AddChild(child);
    }

    void Window::update() {
        PanelTransformable::update();
    }
}
