#include "raylib-cpp.hpp"
#include <iostream>
#include "cursor.hpp"
#include "utils.hpp"
#include "UIComponent.hpp"
void test(void) {
    std::cout << "clicked !" << std::endl;
}

int main() {

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);
    auto * uiComponent = new UIComponent();



    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window w(screenWidth, screenHeight, "NativeUI Showcase");


    SetTargetFPS(30);
    // Main game loop
    while (!w.ShouldClose()) { // Detect window close button or ESC key
        // Draw


        SetCursor(MOUSE_CURSOR_DEFAULT);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
        UpdateCursorState();
    }

    CloseWindow();

    return 0;
}
