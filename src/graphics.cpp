#include "graphics.hpp"

void DrawRoundedRectangle(raylib::Rectangle rect, float cornerRadius, Color color) {
    // Draw main rectangle
    DrawRectangleV(rect.GetPosition() + raylib::Vector2(cornerRadius, 0), rect.GetSize() - raylib::Vector2(2 * cornerRadius, 0), color);
    DrawRectangleV(rect.GetPosition() + raylib::Vector2(0, cornerRadius), raylib::Vector2(cornerRadius, rect.height - 2 * cornerRadius), color);
    DrawRectangleV(rect.GetPosition() + raylib::Vector2(rect.width - cornerRadius, cornerRadius), raylib::Vector2(cornerRadius, rect.height - 2 * cornerRadius), color);

    // Draw corners
    // Top left
    DrawCircleSector(rect.GetPosition() + raylib::Vector2(cornerRadius, cornerRadius), cornerRadius, 180, 270, 5, color);
    // Top right
    DrawCircleSector(rect.GetPosition() + raylib::Vector2(rect.width - cornerRadius, cornerRadius), cornerRadius, -90, 0, 5, color);
    // Bottom left
    DrawCircleSector(rect.GetPosition() + raylib::Vector2(cornerRadius, rect.height - cornerRadius), cornerRadius, 90, 180, 5, color);
    // Bottom right
    DrawCircleSector(rect.GetPosition() + raylib::Vector2(rect.width - cornerRadius, rect.height - cornerRadius), cornerRadius, 0, 90, 5, color);

}

void DrawRoundedRectangleLines(raylib::Rectangle rect, float cornerRadius, Color color, float thickness) {
    // For readability sake
    float x = rect.x;
    float y = rect.y;
    float width = rect.width;
    float height = rect.height;
    float r = cornerRadius;

    // Draw Edges
    DrawLineEx(Vector2{x + r, y}, Vector2{x + width - r, y}, thickness, color);
    DrawLineEx(Vector2{x, y + r}, Vector2{x, y + height - r}, thickness, color);
    DrawLineEx(Vector2{x + width, y + r}, Vector2{x + width, y + height - r}, thickness, color);
    DrawLineEx(Vector2{x + r, y + height}, Vector2{x + width - r, y + height}, thickness, color);

    //Draw corners
    DrawCircleArcLine(rect.GetPosition() + raylib::Vector2(cornerRadius, cornerRadius), cornerRadius, PI / 2, PI, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + raylib::Vector2(rect.width - cornerRadius, cornerRadius), cornerRadius, 0, PI / 2, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + raylib::Vector2(cornerRadius, rect.height - cornerRadius), cornerRadius, -PI, -PI / 2, thickness, 5, color);
    DrawCircleArcLine(rect.GetPosition() + raylib::Vector2(rect.width - cornerRadius, rect.height - cornerRadius), cornerRadius, -PI / 2, 0, thickness, 5, color);

}

void DrawCircleArcLine(raylib::Vector2 center, float radius, float startAngle, float stopAngle, float LineThickness, int segments, Color color) {
    for (int segment = 0; segment < segments; segment++) {
        float t1 = float(segment) / float(segments);
        float t2 = float(segment + 1) / float(segments);

        float angle = (1 - t1) * startAngle + t1 * stopAngle;
        float nextAngle = (1 - t2) * startAngle + t2 * stopAngle;
        DrawLineEx(center + raylib::Vector2(cosf(angle), -sin(angle)) * radius, center + raylib::Vector2(cosf(nextAngle), -sin(nextAngle)) * radius, LineThickness, color);
    }
}
