#include "Panel.hpp"
#include "Widget.hpp"
#include "../backend/inputs.hpp"

namespace widget {
    Panel::Panel(shape::Shape* shape) : Widget(shape), selected(false) {

    }

    void Panel::draw() {
        shape->RenderFilled(GetContainingRectangle(), backend::Color(255, 0, 0, 255));
        if (selected) {
            shape->RenderLines(GetContainingRectangle(), 5, backend::Color());
        }
    }

    void Panel::update() {
        if (backend::IsMousePressed(backend::MOUSE_BUTTON::LEFT)) {
            selected = IsHovered();
        }
    }

}
