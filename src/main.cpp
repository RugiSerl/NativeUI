#include <raylib-cpp.hpp>
#include <string>
#include <iostream>
#include "UICheckbox.hpp"
#include "UITranslatablePanel.hpp"
#include "anchor.hpp"
#include "UIStylebox.hpp"
#include "UISplit.hpp"

void test(void) {
    std::cout << "clicked !" << std::endl;
}


int main() {
    
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // Testing
    UIPanel selectable(raylib::Rectangle(0.0, 20.0, 700.0, 700.0), Anchor2{Anchor::CENTER, Anchor::BOTTOM});
    UITranslatablePanel translatable(raylib::Rectangle(40.0, 40.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::BOTTOM});
    UISelectablePanel selectable2(raylib::Rectangle(-20, 20.0, 50.0, 50.0), Anchor2{Anchor::CENTER, Anchor::BOTTOM});
    UIStylebox stylebox = UIStylebox(1, 0, WHITE, BLACK);
    UIButton button(raylib::Rectangle(-20.0, 20.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::TOP}, test, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, UIStylebox(1, 0, WHITE, GRAY), stylebox);
    selectable.AddChild(&button);
    UICheckbox checkbox(raylib::Rectangle(50, 20.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::TOP}, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, UIStylebox(1, 0, WHITE, GRAY), stylebox);
    selectable.AddChild(&checkbox);
    
    selectable.AddChild(&selectable2);
    UISplit split(raylib::Rectangle(10, 10, 400, 400), Anchor2{Anchor::RIGHT, Anchor::TOP}, VERTICAL_SPLIT, Anchor::TOP, 75);
    selectable.AddChild(&split);
    split.AddChild(&translatable, 1);

    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(165);
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
	    selectable.UpdateAndDraw();
        DrawFPS(0, 0);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
