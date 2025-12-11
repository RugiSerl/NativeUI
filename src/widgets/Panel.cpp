#include "Panel.hpp"
#include "Widget.hpp"
#include <iostream>

namespace widget {
    Panel::Panel(property::Modifier modifier, style::StyleBox stylebox) : Widget(modifier), styleBox(stylebox) {

    }

    void Panel::draw() {

        styleBox.Render(GetRectangle());
    }

    void Panel::update() {

    }

}
