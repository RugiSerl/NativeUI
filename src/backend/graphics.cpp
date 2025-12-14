#include "graphics.hpp"
#include "coordinates.hpp"
#include "raylib.h"
#include "vectors.hpp"
#include <algorithm>

namespace backend {
    void DrawRectangle(const ScreenCoordinate position, const Vector2 size, const Color color) {
        DrawRectangleRec(Rectangle{position.x, position.y, size.x, size.y}, color);
    }

    void DrawCircle(const ScreenCoordinate center, const float radius, const int segments, const Color color) {
        DrawCircleSector(center.ToVector2(), radius, 0, 360, segments, color);
    }

    void DrawRoundedRectangle(const ScreenCoordinate position, const Vector2 size, float cornerRadius, const int segments, const Color color) {
        cornerRadius = std::min(cornerRadius, std::min(size.x, size.y)/2.0f); // Avoid having border radius larger than half of the smallest side.

        // Rectangle at the center.
        DrawRectangle(position+ScreenCoordinate(cornerRadius), size-Vector2(cornerRadius*2), color);

        // Drawing edges.
        // Top
        DrawRectangle(position+ScreenCoordinate(cornerRadius, 0), Vector2(size.x-2*cornerRadius, cornerRadius), color);
        // Bottom
        DrawRectangle(position+ScreenCoordinate(cornerRadius, size.y-cornerRadius), Vector2(size.x-2*cornerRadius, cornerRadius), color);
        // Left
        DrawRectangle(position+ScreenCoordinate(0, cornerRadius), Vector2(cornerRadius, size.y-2*cornerRadius), color);
        // Right
        DrawRectangle(position+ScreenCoordinate(size.x-cornerRadius, cornerRadius), Vector2(cornerRadius, size.y-2*cornerRadius), color);

        // Drawing corners
        // Top left
        DrawCircleSector(position.ToVector2()+Vector2(cornerRadius), cornerRadius, -90, -180, segments, color);
        // Top right
        DrawCircleSector(position.ToVector2()+Vector2(size.x-cornerRadius, cornerRadius), cornerRadius, 0, -90, segments, color);
        // Bottom left
        DrawCircleSector(position.ToVector2()+Vector2(cornerRadius, size.y-cornerRadius), cornerRadius, -180, -270, segments, color);
        // Bottom left
        DrawCircleSector(position.ToVector2()+Vector2(size.x-cornerRadius, size.y-cornerRadius), cornerRadius, 0, 90, segments, color);

    }
}
