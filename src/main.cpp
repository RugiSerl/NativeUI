#include "backend/rectangles.hpp"
#include "backend/vectors.hpp"
#include "properties/Anchor.hpp"
#include "raylib.h"
#include "shape/Circle.hpp"
#include "shape/Rectangle.hpp"
#include "shape/RectangleRounded.hpp"
#include "widgets/Panel.hpp"
#include "widgets/Widget.hpp"

int main() {
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    // SetTraceLogLevel(LOG_ERROR); // temp, disable logging
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "NativeUI Showcase");
    SetTargetFPS(60);

    auto* root = new widget::Widget(
        new shape::Rectangle(property::RelativeCoordinate(0, 0, property::AnchorType::LEFT, property::AnchorType::TOP), 30)
    );


    auto* myWidget = new widget::Panel(
        new shape::RectangleRounded(property::RelativeCoordinate(0, 0, property::AnchorType::MIDDLE, property::AnchorType::BOTTOM), backend::RectangleSize(500, 200), 50)
    );

    auto* myWidget2 = new widget::Panel(
        new shape::Circle(property::RelativeCoordinate(0, 100, property::AnchorType::LEFT, property::AnchorType::TOP), 30)
    );

    root->AddChild(myWidget);
    root->AddChild(myWidget2);


    while (!WindowShouldClose()) {
        // Detect window close button or ESC key
        // Draw

        BeginDrawing();
        ClearBackground(RAYWHITE);
        root->UpdateAndDraw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
