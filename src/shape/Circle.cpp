#include "Circle.hpp"

namespace shape {
    Circle::Circle(float radius) : radius(radius)  {

    }

    bool Circle::GetPointCollision(backend::Vector2 position) const {
        return (backend::Vector2(radius) - position).Length() < radius;
    }

    void Circle::Render(backend::Vector2 position, backend::Color color) const {
        backend::DrawCircle(position+backend::Vector2(radius), radius, 32, color);
    }

    /**
     * Get the bounding box of the shape.
     * Since the origin of the shape is always (0, 0), there is no need
     * for a rectangle object, thus we only return the size of the bounding box.
     */
    backend::Vector2 Circle::GetBoundingBoxSize() const {
        return backend::Vector2(2*radius);
    }
}
