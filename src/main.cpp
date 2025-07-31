#include "UICheckbox.hpp"
#include "UISplit.hpp"
#include "UIStylebox.hpp"
#include "UITranslatablePanel.hpp"
#include "anchor.hpp"
#include <iostream>
#include <raylib-cpp.hpp>
#include <string>
#include "graphics.hpp"
#include "UIResizablePanel.hpp"
#include "cursor.hpp"
#include "utils.hpp"

void test(void) {
    std::cout << "clicked !" << std::endl;
}

int main() {

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);

    // Testing
    UIPanel selectable(raylib::Rectangle(0.0), Anchor2{Anchor::FILL, Anchor::FILL});
    UISplit menusplit(raylib::Rectangle(0), Anchor2{Anchor::FILL, Anchor::FILL}, VERTICAL_SPLIT, Anchor::TOP, 30);
    selectable.AddChild(&menusplit);
    UISplit navigatorSplit(raylib::Rectangle(0), Anchor2{Anchor::FILL, Anchor::FILL}, HORIZONTAL_SPLIT, Anchor::LEFT, 400);
    menusplit.AddChild(&navigatorSplit, 1);

    UIResizablePanel selectable2(raylib::Rectangle(40.0, 40.0, 400.0, 400.0), resizableDirections(false, true, false, false), raylib::Vector2(40, 40));
    UIResizablePanel selectable3(raylib::Rectangle(0, 20.0, 200.0, 200.0), resizableDirections(false, true, false, false), raylib::Vector2(40, 40));
    UIResizablePanel selectable4(raylib::Rectangle(0, 20.0, 50.0, 50.0), resizableDirections(false, true, false, false), raylib::Vector2(40, 40));
    UIButton button(raylib::Rectangle(-20.0, 20.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::TOP}, test, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, DEFAULT_HOVER_STYLEBOX, DEFAULT_BUTTON_DOWN_STYLEBOX);
    navigatorSplit.AddChild(&button, 0);
    UICheckbox checkbox(raylib::Rectangle(50, 20.0, 50.0, 50.0), Anchor2{Anchor::LEFT, Anchor::TOP}, DEFAULT_PANEL_STYLEBOX, DEFAULT_SELECTED_STYLEBOX, DEFAULT_HOVER_STYLEBOX, DEFAULT_BUTTON_DOWN_STYLEBOX);

    UIResizablePanel panel(raylib::Rectangle(40.0, 40.0, 200.0, 200.0), resizableDirections(false, true, false, false), raylib::Vector2(40, 40));

    navigatorSplit.AddChild(&panel, 0);
    selectable3.AddChild(&checkbox);
    selectable2.AddChild(&selectable3);
    selectable3.AddChild(&selectable4);
    navigatorSplit.AddChild(&selectable2, 1);

    raylib::Color textColor(LIGHTGRAY);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window w(screenWidth, screenHeight, "NativeUI Showcase");


    SetTargetFPS(165);

    // Main game loop
    while (!w.ShouldClose()) { // Detect window close button or ESC key
        // Draw
        SetCursor(MOUSE_CURSOR_DEFAULT);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        selectable.UpdateAndDraw();

        DrawFPS(0, 0);
        EndDrawing();
        UpdateCursorState();
    }

    CloseWindow();

    return 0;
}
