//
// Created by raphael on 11/2/25.
//

#ifndef NATIVEUI_CANVAS_HPP
#define NATIVEUI_CANVAS_HPP
#include <functional>

#include "Component.hpp"
#include "Image.hpp"
#include "RenderTexture.hpp"

namespace UIComponent {
    class Canvas : public Image{
    public:
        Canvas(Modifier modifier, LayoutType layout);
        ~Canvas() override = default;

        /**
         * @brief Render content inside the canvas. You can render pretty much everything you can render on a normal
         * windows. You have to pass a function in which you execute the draw calls.
         * @param drawCalls function containing all the draw calls.
         *
         * Example :
         * @code
         * canvas->Render([] {
         *     ClearBackground(GRAY);
         *     DrawCircleV(raylib::Vector2(100, 100), 50, BLACK);
         *     DrawRectangleV(raylib::Vector2(300, 150), raylib::Vector2(50, 100), RED);
         * });
         */
        void Render(std::function<void ()> drawCalls);

        /**
         * @brief Computes the position that would be in the canvas from a screen space position.
         * @param absolutePosition position we want to convert
         * @return The position relative to the canvas
         */
        raylib::Vector2 GetRelativePosition(raylib::Vector2 absolutePosition) const;

        /**
         * @brief Shortcut for GetRelativePosition() with mouse coordinates
         * @return The mouse position relative to the canvas.
         */
        raylib::Vector2 GetMouseRelativePosition() const;

        void draw() override;
    private:
        raylib::RenderTexture renderTexture;
    };
} // UIComponent

#endif //NATIVEUI_CANVAS_HPP