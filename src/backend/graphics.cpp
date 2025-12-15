#include "graphics.hpp"
#include "coordinates.hpp"
#include "raylib.h"
#include "rectangles.hpp"
#include "vectors.hpp"
#include <algorithm>

namespace backend {
    void DrawRectangle(const ScreenCoordinate position, const RectangleSize size, const Color color) {
        DrawRectangleRec(Rectangle{position.x, position.y, size.GetX(), size.GetY()}, color);
    }

    void DrawCircle(const ScreenCoordinate center, const float radius, const int segments, const Color color) {
        DrawCircleSector(center.ToVector2(), radius, 0, 360, segments, color);
    }

    void DrawRoundedRectangle(const ScreenCoordinate position, const RectangleSize size, float cornerRadius, const int segments, const Color color) {
        cornerRadius = std::min(cornerRadius, std::min(size.GetX(), size.GetY())/2.0f); // Avoid having border radius larger than half of the smallest side.

        // Rectangle at the center.
        DrawRectangle(position+ScreenCoordinate(cornerRadius), size-RectangleSize(cornerRadius*2), color);

        // Drawing edges.
        // Top
        DrawRectangle(position+ScreenCoordinate(cornerRadius, 0), RectangleSize(size.GetX()-2*cornerRadius, cornerRadius), color);
        // Bottom
        DrawRectangle(position+ScreenCoordinate(cornerRadius, size.GetY()-cornerRadius), RectangleSize(size.GetX()-2*cornerRadius, cornerRadius), color);
        // Left
        DrawRectangle(position+ScreenCoordinate(0, cornerRadius), RectangleSize(cornerRadius, size.GetY()-2*cornerRadius), color);
        // Right
        DrawRectangle(position+ScreenCoordinate(size.GetX()-cornerRadius, cornerRadius), RectangleSize(cornerRadius, size.GetY()-2*cornerRadius), color);

        // Drawing corners
        // Top left
        DrawCircleSector(position.ToVector2()+Vector2(cornerRadius), cornerRadius, -90, -180, segments, color);
        // Top right
        DrawCircleSector(position.ToVector2()+Vector2(size.GetX()-cornerRadius, cornerRadius), cornerRadius, 0, -90, segments, color);
        // Bottom left
        DrawCircleSector(position.ToVector2()+Vector2(cornerRadius, size.GetY()-cornerRadius), cornerRadius, -180, -270, segments, color);
        // Bottom left
        DrawCircleSector(position.ToVector2()+Vector2(size.GetX()-cornerRadius, size.GetY()-cornerRadius), cornerRadius, 0, 90, segments, color);

    }
}
