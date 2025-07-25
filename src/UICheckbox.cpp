#include "UICheckbox.hpp"
#include "utils.hpp"
UICheckbox::UICheckbox(raylib::Rectangle r, Anchor2 a,
                       UIStylebox normalStylebox, UIStylebox selectedStylebox,
                       UIStylebox hoveredStylebox, UIStylebox downStylebox)
    : UIButton(r, a, [this]() {
    value = !value;
}, normalStylebox, selectedStylebox, hoveredStylebox, downStylebox), value(false) {};

void UICheckbox::draw(raylib::Rectangle boundingBox) {
    UIButton::draw(boundingBox);

    if (value) {
        // drawing inside of checkbox if active
        raylib::Rectangle anchoredRect = GetAnchoredRect(rect, anchor, boundingBox);
        UIStylebox(0, stylebox.cornerRadius, BLACK, BLACK)
        .draw(raylib::Rectangle(rect.GetSize() * 0.67), Anchor2{CENTER, CENTER},
              anchoredRect);
    }
}