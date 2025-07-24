#include <raylib-cpp.hpp>
#include <string>
#include "UIButton.hpp"
#include "UITranslatablePanel.hpp"
#include "anchor.hpp"
#include "UIStylebox.hpp"
#include "UISplit.hpp"

int main() {
    
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    UISelectablePanel selectable(raylib::Rectangle(0.0, 20.0, 700.0, 700.0), Anchor2{Anchor::CENTER, Anchor::BOTTOM});
    UITranslatablePanel translatable(raylib::Rectangle(20.0, 20.0, 50.0, 50.0), Anchor2{Anchor::CENTER, Anchor::BOTTOM});
    UISelectablePanel selectable2(raylib::Rectangle(-20, 20.0, 50.0, 50.0), Anchor2{Anchor::CENTER, Anchor::BOTTOM});
    UIStylebox stylebox = UIStylebox(1, 0, WHITE, BLACK);
    UIButton button(raylib::Rectangle(-20.0, 20.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::TOP}, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, UIStylebox(1, 0, WHITE, GRAY), stylebox);
    selectable.AddChild(&button);
    selectable.AddChild(&translatable);
    selectable.AddChild(&selectable2);
    UISplit split(raylib::Rectangle(0, 0, 150, 150), Anchor2{Anchor::RIGHT, Anchor::TOP}, HORIZONTAL_SPLIT, Anchor::RIGHT, 50);
    selectable.AddChild(&split);

    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(-1);
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        selectable.UpdateAndDraw();
        EndDrawing();
    }

    return 0;
}