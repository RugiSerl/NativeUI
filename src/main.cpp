#include "backend/rectangles.hpp"
#include "coordinates/Anchor.hpp"
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
        new shape::Rectangle(coordinates::RelativeCoordinate(0, 0, coordinates::AnchorType::FILL, coordinates::AnchorType::FILL), 30)
    );


    auto* myWidget = new widget::Panel(
        new shape::RectangleRounded(coordinates::RelativeCoordinate(0, 0, coordinates::AnchorType::MIDDLE, coordinates::AnchorType::BOTTOM), backend::RectangleSize(500, 200), 50)
    );

    auto* myWidget2 = new widget::Panel(
        new shape::Circle(coordinates::RelativeCoordinate(0, 100, coordinates::AnchorType::LEFT, coordinates::AnchorType::TOP), 30)
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
