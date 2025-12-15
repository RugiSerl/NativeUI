#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/inputs.hpp"
#include "../backend/windows.hpp"

namespace widget {
    Panel::Panel(property::Modifier modifier, shape::Shape* shape) : Widget(modifier, shape) {

    }

    void Panel::draw() {
        property::BoundingBox bb(backend::ScreenCoordinate(0, 0), backend::GetWindowSize());
        if (shape->GetPointCollision(bb, backend::GetMousePosition())) {
            shape->Render(bb, backend::Color(255, 0, 0, 255));
        } else {
            shape->Render(bb, backend::Color());
        }
    }

    void Panel::update() {

    }

}
