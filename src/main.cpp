#include "UICheckbox.hpp"
#include "UISplit.hpp"
#include "UIStylebox.hpp"
#include "UITranslatablePanel.hpp"
#include "anchor.hpp"
#include <iostream>
#include <raylib-cpp.hpp>
#include <string>

void test(void) {
    std::cout << "clicked !" << std::endl;
}

int main() {

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // Testing
    UIPanel selectable(raylib::Rectangle(0.0),
                       Anchor2{Anchor::FILL, Anchor::FILL});
    UISplit menusplit(raylib::Rectangle(0), Anchor2{Anchor::FILL, Anchor::FILL},
                      VERTICAL_SPLIT, Anchor::TOP, 30);
    selectable.AddChild(&menusplit);
    UISplit navigatorSplit(raylib::Rectangle(0),
                           Anchor2{Anchor::FILL, Anchor::FILL}, HORIZONTAL_SPLIT,
                           Anchor::LEFT, 400);
    menusplit.AddChild(&navigatorSplit, 1);

    UITranslatablePanel translatable(raylib::Rectangle(40.0, 40.0, 50.0, 50.0));
    UISelectablePanel selectable2(raylib::Rectangle(-20, 20.0, 50.0, 50.0),
                                  Anchor2{Anchor::CENTER, Anchor::TOP});
    UIStylebox stylebox = UIStylebox(1, 0, WHITE, BLACK);
    UIButton button(raylib::Rectangle(-20.0, 20.0, 50.0, 50.0),
                    Anchor2{Anchor::LEFT, Anchor::TOP}, test,
                    DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX,
                    UIStylebox(1, 0, WHITE, GRAY), stylebox);
    navigatorSplit.AddChild(&button, 0);
    UICheckbox checkbox(raylib::Rectangle(50, 20.0, 50.0, 50.0),
                        Anchor2{Anchor::LEFT, Anchor::TOP},
                        DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX,
                        UIStylebox(1, 0, WHITE, GRAY), stylebox);
    navigatorSplit.AddChild(&checkbox, 0);

    navigatorSplit.AddChild(&selectable2, 0);

    navigatorSplit.AddChild(&translatable, 0);

    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");

    SetTargetFPS(165);

    // Main game loop
    while (!w.ShouldClose()) { // Detect window close button or ESC key
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
