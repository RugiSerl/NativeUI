#include "PanelTranslatable.hpp"
#include "Panel.hpp"
#include "../backend/graphics.hpp"

namespace widget {
    PanelTranslatable::PanelTranslatable(shape::Shape* shape) : Panel(shape) {

    }

    void PanelTranslatable::update() {
        Panel::update();
        if (selected && backend::IsMouseDown(backend::MOUSE_BUTTON::LEFT)) {
            shape->Move(backend::GetMouseDelta());
        }
    }

    void PanelTranslatable::draw() const {
        Panel::draw();
        // For debug purposes.
        // coordinates::ScreenRectangle rect = shape->GetScreenRectangle(GetContainingRectangle());
        // backend::DrawRectangleLines(rect.position, rect.size, 3, backend::Color());
    }
}
