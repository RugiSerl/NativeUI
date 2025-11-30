#include "UIComponent/TextEntry.hpp"
#include "Vector2.hpp"
#include "Properties/Anchor.hpp"
#include <iostream>

#include "UIComponent/Button.hpp"
#include "UIComponent/Canvas.hpp"
#include "UIComponent/CanvasDynamic.hpp"
#include "cursor.hpp"
#include "UIComponent/Component.hpp"
#include "UIComponent/Panel.hpp"
#include "UIComponent/PanelTransformable.hpp"
#include "UIComponent/Window.hpp"

void test() {
    std::cout << "clicked !" << std::endl;
}

int main() {
    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window w(screenWidth, screenHeight, "NativeUI Showcase");

    SetTargetFPS(60);
    // Main game loop


    auto *root = new UIComponent::Panel(Modifier()
                           .setPosition(raylib::Vector2(0, 0))
                           .setSize(raylib::Vector2(0, 0))
                           .setAnchor(Anchor2{Anchor::FILL, Anchor::FILL}),
                           LayoutType::NONE
    );


    auto img = new UIComponent::Image(
    Modifier()
            .setPosition(raylib::Vector2(10, 10))
            .setSize(raylib::Vector2(300, 300))
            .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
            LayoutType::NONE,
        "./res/icon.png"
    );

    auto *window = new UIComponent::Window(
        "Test",
        Modifier()
        .setPosition(raylib::Vector2(0, 0))
        .setSize(raylib::Vector2(400, 300))
        .setAnchor(Anchor2{Anchor::RIGHT, Anchor::TOP}));

    auto *uiComponent = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(10, 10))
        .setSize(raylib::Vector2(300, 300))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::NONE);

    auto *uiComponent2 = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::NONE
    );

    auto *uiComponent3 = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::NONE);

    auto *button = new UIComponent::Button(
        Modifier()
        .setPosition(raylib::Vector2(40, 20))
        .setSize(raylib::Vector2(50, 50))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::NONE,
        [window]{window->Show();});

    auto *panel = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(600, 600))
        .setSize(raylib::Vector2(150, 150))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::ROW);

    auto *rowChild1 = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(50, 50))
        .setSize(raylib::Vector2(60, 60))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::ROW);

    auto *rowChild2 = new UIComponent::PanelTransformable(
        Modifier()
        .setPosition(raylib::Vector2(50, 50))
        .setSize(raylib::Vector2(20, 20))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::ROW);

    auto *canvas = new UIComponent::CanvasDynamic(
        Modifier()
        .setPosition(raylib::Vector2(50, 50))
        .setSize(raylib::Vector2(400, 400))
        .setAnchor(Anchor2{Anchor::LEFT, Anchor::TOP}),
        LayoutType::ROW);

    auto *textEntry = new UIComponent::TextEntry(
        Modifier()
        .setPosition(raylib::Vector2(200, 200))
        .setSize(raylib::Vector2(200, 200))
        .setAnchor(Anchor2(Anchor::RIGHT, Anchor::TOP)),
        LayoutType::NONE
    );


    panel->AddChild(rowChild1);
    panel->AddChild(rowChild2);
    uiComponent->AddChild(uiComponent3);
    uiComponent2->AddChild(button);
    root->AddChild(uiComponent);
    root->AddChild(uiComponent2);
    root->AddChild(panel);
    // window->AddChild(img);
    window->AddChild(canvas);
    root->AddChild(window);
    root->AddChild(textEntry);




    while (!w.ShouldClose()) {
        // Detect window close button or ESC key
        // Draw

        SetCursor(MOUSE_CURSOR_DEFAULT);
        BeginDrawing();
        root->UpdateAndDraw();
        canvas->Render([canvas] {
            ClearBackground(GRAY);
            DrawCircleV(canvas->GetMouseRelativePosition(), 50, BLACK);
            DrawRectangleV(raylib::Vector2(300, 150), raylib::Vector2(50, 100), RED);

        });

        EndDrawing();
        UpdateCursorState();
    }

    CloseWindow();

    return 0;
}
