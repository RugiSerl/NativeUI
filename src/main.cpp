#include "raylib-cpp.hpp"
#include <iostream>

#include "Button.hpp"
#include "cursor.hpp"
#include "utils.hpp"
#include "Component.hpp"
#include "Panel.hpp"
#include "PanelResizable.hpp"
#include "Theme.hpp"

void test(void) {
    std::cout << "clicked !" << std::endl;
}

int main() {

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);
    auto *root = new Panel(Modifier()
        .setPosition(raylib::Vector2(0, 0))
        .setSize(raylib::Vector2(0, 0))
        .setAnchor(Anchor2{Anchor::FILL, Anchor::FILL})
    );


    auto *uiComponent = new PanelResizable(
        Modifier()
        .setPosition(raylib::Vector2(10, 10))
        .setSize(raylib::Vector2(300, 300))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        raylib::Vector2(20, 20));

    auto * uiComponent2 = new PanelResizable(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        raylib::Vector2(20, 50));

    auto * uiComponent3 = new PanelResizable(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        raylib::Vector2(20, 50));

    auto * button = new Button(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        test);

    uiComponent->AddChild(uiComponent3);
    uiComponent2->AddChild(button);
    root->AddChild(uiComponent);
    root->AddChild(uiComponent2);


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window w(screenWidth, screenHeight, "NativeUI Showcase");


    SetTargetFPS(144);
    // Main game loop
    while (!w.ShouldClose()) { // Detect window close button or ESC key
        // Draw

        SetCursor(MOUSE_CURSOR_DEFAULT);
        BeginDrawing();
        root->UpdateAndDraw();

        EndDrawing();
        UpdateCursorState();
    }

    CloseWindow();

    return 0;
}
