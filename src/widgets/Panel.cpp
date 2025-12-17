#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/inputs.hpp"
#include "../backend/windows.hpp"

namespace widget {
    Panel::Panel(shape::Shape* shape) : Widget(shape) {

    }

    void Panel::draw() {
        property::ScreenRectangle bb(backend::ScreenCoordinate(0, 0), backend::GetWindowSize());
        shape->RenderFilled(bb, backend::Color(255, 0, 0, 255));
        if (shape->GetPointCollision(bb, backend::GetMousePosition())) {
            shape->RenderLines(bb, 5, backend::Color());
        }
    }

    void Panel::update() {

    }

}
