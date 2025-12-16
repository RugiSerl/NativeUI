#include "backend/rectangles.hpp"
#include "backend/vectors.hpp"
#include "raylib.h"
#include "shape/Circle.hpp"
#include "shape/Rectangle.hpp"
#include "shape/RectangleRounded.hpp"
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
            .withPosition(backend::Vector2(20, 20)),
        new shape::RectangleRounded(property::RelativeCoordinate(0, 0, property::AnchorType::MIDDLE, property::AnchorType::BOTTOM), backend::RectangleSize(500, 200), 50)
    );


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
