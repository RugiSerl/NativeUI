#include "graphics.hpp"

void DrawRoundedRectangle(const math::Rectangle rect, const float cornerRadius, const Color color) {

    auto raylibRectangle = rect.ToRaylibRectangle();
    // Draw main rectangle
    DrawRectangleV(raylibRectangle.GetPosition() + raylib::Vector2(cornerRadius, 0), raylibRectangle.GetSize() - raylib::Vector2(2 * cornerRadius, 0), color);
    DrawRectangleV(raylibRectangle.GetPosition() + raylib::Vector2(0, cornerRadius), raylib::Vector2(cornerRadius, raylibRectangle.height - 2 * cornerRadius), color);
    DrawRectangleV(raylibRectangle.GetPosition() + raylib::Vector2(raylibRectangle.width - cornerRadius, cornerRadius), raylib::Vector2(cornerRadius, raylibRectangle.height - 2 * cornerRadius), color);

    // Draw corners
    // Top left
    DrawCircleSector(raylibRectangle.GetPosition() + raylib::Vector2(cornerRadius, cornerRadius), cornerRadius, 180, 270, 5, color);
    // Top right
    DrawCircleSector(raylibRectangle.GetPosition() + raylib::Vector2(raylibRectangle.width - cornerRadius, cornerRadius), cornerRadius, -90, 0, 5, color);
    // Bottom left
    DrawCircleSector(raylibRectangle.GetPosition() + raylib::Vector2(cornerRadius, raylibRectangle.height - cornerRadius), cornerRadius, 90, 180, 5, color);
    // Bottom right
    DrawCircleSector(raylibRectangle.GetPosition() + raylib::Vector2(raylibRectangle.width - cornerRadius, raylibRectangle.height - cornerRadius), cornerRadius, 0, 90, 5, color);
}

void DrawRoundedRectangleLines(math::Rectangle rect, float cornerRadius, Color color, float thickness) {

    // Adjust for screen dpi
    thickness *= raylib::Window::GetScaleDPI().x;
    cornerRadius *= raylib::Window::GetScaleDPI().x;

    // For readability’s sake
    const float x = rect.x;
    const float y = rect.y;
    const float width = rect.width;
    const float height = rect.height;
    const float r = cornerRadius;

    // Draw Edges
    DrawLineEx(Vector2{x + r, y}, Vector2{x + width - r, y}, thickness, color);
    DrawLineEx(Vector2{x, y + r}, Vector2{x, y + height - r}, thickness, color);
    DrawLineEx(Vector2{x + width, y + r}, Vector2{x + width, y + height - r}, thickness, color);
    DrawLineEx(Vector2{x + r, y + height}, Vector2{x + width - r, y + height}, thickness, color);

    //Draw corners
    DrawCircleArcLine(rect.GetPosition() + math::Vector2(cornerRadius, cornerRadius), cornerRadius, PI / 2, PI, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + math::Vector2(rect.width - cornerRadius, cornerRadius), cornerRadius, 0, PI / 2, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + math::Vector2(cornerRadius, rect.height - cornerRadius), cornerRadius, -PI, -PI / 2, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + math::Vector2(rect.width - cornerRadius, rect.height - cornerRadius), cornerRadius, -PI / 2, 0, thickness, 5, color);
}

void DrawCircleArcLine(math::Vector2 center, float radius, float startAngle, float stopAngle, float lineThickness, int segments, Color color) {
    for (int segment = 0; segment < segments; segment++) {
        float t1 = float(segment) / float(segments);
        float t2 = float(segment + 1) / float(segments);

        float angle = (1 - t1) * startAngle + t1 * stopAngle;
        float nextAngle = (1 - t2) * startAngle + t2 * stopAngle;
        DrawLineEx(center.ToRaylibVector2() + raylib::Vector2(cosf(angle), -sin(angle)) * radius, center.ToRaylibVector2() + raylib::Vector2(cosf(nextAngle), -sin(nextAngle)) * radius, lineThickness, color);
    }
}
