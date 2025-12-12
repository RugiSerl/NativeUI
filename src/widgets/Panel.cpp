#include "Panel.hpp"
#include "Widget.hpp"

namespace widget {
    Panel::Panel(property::Modifier modifier, shape::Shape* shape) : Widget(modifier, shape) {

    }

    void Panel::draw() {
        shape->Render(modifier.position);
    }

    void Panel::update() {

    }

}
