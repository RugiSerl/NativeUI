#include "RectangleRounded.hpp"
#include "Rectangle.hpp"
#include <algorithm>

namespace shape {
    RectangleRounded::RectangleRounded(property::RelativeCoordinate, backend::Vector2 size, float cornerRadius) : Rectangle(position, size), cornerRadius(cornerRadius) {

    }
    /**
     * The collision is calculated on whether the point is in rect 1 or 2, or in the corners.
     * Little ascii art:
     *  ____________
     * /_|_ _2_ _ |_\
     * | |        | |
     * |1|  1&2   |1|
     * |_|_ _ _ _ |_|
     * \_|___2____|_/
     *  ^----------^--- corners
     */
    bool RectangleRounded::GetPointCollision(backend::ScreenCoordinate point) const {

        // auto rectangle1 = Rectangle(position.ToScreenCoordinate()+backend::ScreenCoordinate(0, cornerRadius), backend::Vector2(size.x, std::max(size.y-cornerRadius*2, 0.0f)));
        // auto rectangle2 = Rectangle(position.ToScreenCoordinate()+backend::ScreenCoordinate(cornerRadius, 0), backend::Vector2(std::max(size.x-cornerRadius*2, 0.0f), size.y));

        // return rectangle1.GetPointCollision(point) ||
        //        rectangle2.GetPointCollision(point);
        return true;
    }

    void RectangleRounded::Render(backend::Color color) const {
    }
}
