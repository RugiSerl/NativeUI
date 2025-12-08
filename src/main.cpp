#include "raylib.h"
#include <iostream>
void test() {
    std::cout << "clicked !" << std::endl;
}

int main() {
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    // SetTraceLogLevel(LOG_ERROR); // temp, disable logging
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "NativeUI Showcase");
    SetTargetFPS(60);
    // Main game loop



    while (!WindowShouldClose()) {
        // Detect window close button or ESC key
        // Draw

        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
