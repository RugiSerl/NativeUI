#include "Widget.hpp"

namespace widget {
    Widget::Widget(property::Modifier modifier) : modifier(modifier) {

    }

    void Widget::update() {
        // Do nothing. Supposed to be overriden by deriving classes
    }

    void Widget::draw() {
        // Do nothing. Supposed to be overriden by deriving classes
    }
}
