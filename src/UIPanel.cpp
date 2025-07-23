#include "UIPanel.hpp"

UIPanel::UIPanel(raylib::Rectangle r, Anchor2 a, UIStylebox s) : UIComponent(r, a), stylebox(s) {} 

void UIPanel::draw(raylib::Rectangle boundingBox) {
    stylebox.draw(rect, anchor, boundingBox);
}
