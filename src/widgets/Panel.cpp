#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/inputs.hpp"
#include "../backend/windows.hpp"

namespace widget {
    Panel::Panel(property::Modifier modifier, shape::Shape* shape) : Widget(modifier, shape) {

    }

    void Panel::draw() {
        property::BoundingBox bb(backend::ScreenCoordinate(0, 0), backend::GetWindowSize());
        shape->RenderFilled(bb, backend::Color(255, 0, 0, 255));
        if (shape->GetPointCollision(bb, backend::GetMousePosition())) {
            shape->RenderLines(bb, 5, backend::Color());
        }
    }

    void Panel::update() {

    }

}
