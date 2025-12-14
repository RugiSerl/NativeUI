#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/inputs.hpp"

namespace widget {
    Panel::Panel(property::Modifier modifier, shape::Shape* shape) : Widget(modifier, shape) {

    }

    void Panel::draw() {
        if (shape->GetPointCollision(backend::GetMousePosition())) {
            shape->Render(backend::Color(255, 0, 0, 255));
        } else {
            shape->Render(backend::Color());
        }
    }

    void Panel::update() {

    }

}
