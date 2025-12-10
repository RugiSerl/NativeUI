#include "Stylebox.hpp"

namespace style {
    StyleBox::StyleBox(float cornerRadius, float borderwidth, backend::Color fillColor, backend::Color borderColor)
        : cornerRadius(cornerRadius), borderwidth(borderwidth), fillColor(fillColor), borderColor(borderColor){
    }

    void StyleBox::Render(backend::Rectangle target) {
        target.Draw(backend::Color());
    }
}
