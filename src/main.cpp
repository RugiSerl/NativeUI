#include "raylib-cpp.hpp"
#include <iostream>
#include "cursor.hpp"
#include "utils.hpp"
#include "Component.hpp"
#include "Panel.hpp"
#include "Theme.hpp"

void test(void) {
    std::cout << "clicked !" << std::endl;
}

int main() {

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);
    auto * root = new Panel(raylib::Vector2(0, 0), raylib::Vector2(0, 0), Anchor2{Anchor::FILL, Anchor::FILL}, DEFAULT_STYLE);
    auto * uiComponent = new Panel(raylib::Vector2(10, 10), raylib::Vector2(50, 50), Anchor2{Anchor::LEFT, Anchor::TOP}, DEFAULT_STYLE);
    auto * uiComponent2 = new Panel(raylib::Vector2(40, 20), raylib::Vector2(50, 50), Anchor2{Anchor::LEFT, Anchor::TOP}, DEFAULT_STYLE);

    root->AddChild(uiComponent);
    root->AddChild(uiComponent2);


    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window w(screenWidth, screenHeight, "NativeUI Showcase");


    SetTargetFPS(30);
    // Main game loop
    while (!w.ShouldClose()) { // Detect window close button or ESC key
        // Draw

        root->UpdateAndDraw();
        SetCursor(MOUSE_CURSOR_DEFAULT);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
        UpdateCursorState();
    }

    CloseWindow();

    return 0;
}
