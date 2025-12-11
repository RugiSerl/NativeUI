#include "properties/Modifier.hpp"
#include "raylib.h"
#include "widgets/Panel.hpp"
#include "widgets/Widget.hpp"
#include <iostream>

int main() {
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    // SetTraceLogLevel(LOG_ERROR); // temp, disable logging
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "NativeUI Showcase");
    SetTargetFPS(60);




    auto* myWidget = new widget::Panel(
        property::Modifier()
            .withSize(backend::Vector2(400, 400))
            .withPosition(backend::Vector2(20, 20))
    );

    auto* myWidget2 = new widget::Panel(
        property::Modifier()
            .withSize(backend::Vector2(400, 400))
            .withPosition(backend::Vector2(20, 20))
    );

    myWidget->AddChild(myWidget2);

    while (!WindowShouldClose()) {
        // Detect window close button or ESC key
        // Draw

        BeginDrawing();
        ClearBackground(RAYWHITE);
        myWidget->UpdateAndDraw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
