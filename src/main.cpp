#include "properties/Modifier.hpp"
#include "raylib.h"
#include "widgets/Widget.hpp"

int main() {
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    // SetTraceLogLevel(LOG_ERROR); // temp, disable logging
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "NativeUI Showcase");
    SetTargetFPS(60);
    // Main game loop

    widget::Widget myWidget(
        property::Modifier()
            .withSize(backend::Vector2(400, 400))
            .withPosition(backend::Vector2(20, 20))

    );



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
