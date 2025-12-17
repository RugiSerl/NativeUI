#include "graphics.hpp"
#include "raylib.h"
#include "rectangles.hpp"
#include "vectors.hpp"
#include <algorithm>
#include <cmath>

namespace backend {
    void DrawRectangle(coordinates::ScreenCoordinate position, RectangleSize size, Color color) {
        DrawRectangleRec(Rectangle{position.x, position.y, size.GetX(), size.GetY()}, color);
    }

    void DrawRectangleLines(coordinates::ScreenCoordinate position, RectangleSize size, float lineWidth, Color color) {
        DrawRectangleLinesEx(Rectangle{position.x, position.y, size.GetX(), size.GetY()}, lineWidth, color);
    }

    void DrawCircle(coordinates::ScreenCoordinate center, float radius, int segments, Color color) {
        DrawCircleSector(center.ToVector2(), radius, 0, 360, segments, color);
    }

    void DrawCircleLines(coordinates::ScreenCoordinate center, float radius, int segments, float lineWidth, Color color) {
        DrawCircleArcLines(center, radius, 0, 2*PI, segments, lineWidth, color);
    }

    void DrawCircleArcLines(coordinates::ScreenCoordinate center, float radius, float startAngle, float endAngle, int segments, float lineWidth, Color color) {
        for (int i = 0; i < segments; i++) {
            float t = float(i)/float(segments);
            float t2 = float(i+1)/float(segments);
            DrawLineEx(Vector2(center.x + radius * std::cos(startAngle * (1 - t) + endAngle * t), center.y - radius * std::sin(startAngle * (1 - t) + endAngle * t)),
                       Vector2(center.x + radius * std::cos(startAngle * (1 - t2) + endAngle * t2), center.y - radius * std::sin(startAngle * (1 - t2) + endAngle * t2)),
                       lineWidth,
                       color);
        }
    }

    void DrawRoundedRectangle(coordinates::ScreenCoordinate position, RectangleSize size, float cornerRadius, int segments, Color color) {
        cornerRadius = std::min(cornerRadius, std::min(size.GetX(), size.GetY())/2.0f); // Avoid having border radius larger than half of the smallest side.
        // Rectangle at the center.
        DrawRectangle(position+coordinates::ScreenCoordinate(cornerRadius), size-RectangleSize(cornerRadius*2), color);

        // Drawing edges.
        // Top
        DrawRectangle(position+coordinates::ScreenCoordinate(cornerRadius, 0), RectangleSize(size.GetX()-2*cornerRadius, cornerRadius), color);
        // Bottom
        DrawRectangle(position+coordinates::ScreenCoordinate(cornerRadius, size.GetY()-cornerRadius), RectangleSize(size.GetX()-2*cornerRadius, cornerRadius), color);
        // Left
        DrawRectangle(position+coordinates::ScreenCoordinate(0, cornerRadius), RectangleSize(cornerRadius, size.GetY()-2*cornerRadius), color);
        // Right
        DrawRectangle(position+coordinates::ScreenCoordinate(size.GetX()-cornerRadius, cornerRadius), RectangleSize(cornerRadius, size.GetY()-2*cornerRadius), color);

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
    void DrawRoundedRectangleLines(coordinates::ScreenCoordinate position, RectangleSize size, float cornerRadius, float lineWidth, int segments, Color color) {
        // Drawing edges
        // Top
        DrawLineEx((position+coordinates::ScreenCoordinate(cornerRadius, 0)).ToVector2(), (position+coordinates::ScreenCoordinate(size.GetX()-cornerRadius, 0)).ToVector2(), lineWidth, color);
        // Bottom
        DrawLineEx((position+coordinates::ScreenCoordinate(cornerRadius, size.GetY())).ToVector2(), (position+coordinates::ScreenCoordinate(size.GetX()-cornerRadius, size.GetY())).ToVector2(), lineWidth, color);
        // Left
        DrawLineEx((position+coordinates::ScreenCoordinate(0, cornerRadius)).ToVector2(), (position+coordinates::ScreenCoordinate(0, size.GetY()-cornerRadius)).ToVector2(), lineWidth, color);
        // Right
        DrawLineEx((position+coordinates::ScreenCoordinate(size.GetX(), cornerRadius)).ToVector2(), (position+coordinates::ScreenCoordinate(size.GetX(), size.GetY()-cornerRadius)).ToVector2(), lineWidth, color);

        // Top left
        DrawCircleArcLines(position+coordinates::ScreenCoordinate(cornerRadius), cornerRadius, PI/2, PI, segments, lineWidth, color);
        // Top right
        DrawCircleArcLines(position+coordinates::ScreenCoordinate(size.GetX() - cornerRadius, cornerRadius), cornerRadius, 0, PI/2, segments, lineWidth, color);
        // Bottom left
        DrawCircleArcLines(position+coordinates::ScreenCoordinate(cornerRadius, size.GetY() - cornerRadius), cornerRadius, -PI/2, -PI, segments, lineWidth, color);
        // Bottom right
        DrawCircleArcLines(position+coordinates::ScreenCoordinate(size.GetX() - cornerRadius, size.GetY() - cornerRadius), cornerRadius, 0, -PI/2, segments, lineWidth, color);
    }

}
