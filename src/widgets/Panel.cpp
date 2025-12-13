#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/input.hpp"

namespace widget {
    Panel::Panel(property::Modifier modifier, shape::Shape* shape) : Widget(modifier, shape) {

    }

    void Panel::draw() {
        if (shape->GetPointCollision(backend::GetMousePosition()-modifier.position)) {
            shape->Render(modifier.position, backend::Color(255, 0, 0, 255));
        } else {
            shape->Render(modifier.position, backend::Color());
        }
    }

    void Panel::update() {

    }

}
