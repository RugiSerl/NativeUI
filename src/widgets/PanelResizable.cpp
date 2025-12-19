#include "PanelResizable.hpp"
#include "Panel.hpp"

namespace widget {
    PanelTransformable::PanelTransformable(shape::Rectangle* shape) : Panel(shape) {

    }

    void PanelTransformable::update() {
        Panel::update();
        if (selected && backend::IsMouseDown(backend::MOUSE_BUTTON::LEFT)) {
            shape->Move(backend::GetMouseDelta());
        }
    }
}
