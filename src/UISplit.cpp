#include "UISplit.hpp"
#include <iostream>

UISplit::UISplit(raylib::Rectangle r, Anchor2 a, splitType type, Anchor barAnchor, float barOffset, UIStylebox normalStylebox, UIStylebox selectedStylebox) : UISelectablePanel(r, a, normalStylebox, selectedStylebox), type(type), barOffset(barOffset) {
    this->barAnchor = Anchor2 {barAnchor, barAnchor};
    if (type == VERTICAL_SPLIT) {
        this->barAnchor.horizontal = FILL;
    } else {
        this->barAnchor.vertical = FILL;
    }

}
// TODO: not finished
void UISplit::UpdateAndDraw(raylib::Rectangle boundingBox) {

    if (visible) {
        raylib::Rectangle barRect = GetAnchoredRect(raylib::Rectangle((type==HORIZONTAL_SPLIT)*barOffset, (type==VERTICAL_SPLIT)*barOffset, (type==HORIZONTAL_SPLIT)*BAR_WIDTH, (type==VERTICAL_SPLIT)*BAR_WIDTH), barAnchor, GetAnchoredRect(rect, anchor, boundingBox));
        UISelectablePanel::draw(boundingBox);
        barRect.Draw(LIGHTGRAY);

        raylib::Rectangle firstCategoryRect();
        raylib::Rectangle secondCategoryRect();

        

        for (UIComponent* child: this->children) {
            child->UpdateAndDraw(boundingBox);
        }
        for (UIComponent* child: this->secondCategoryChildren) {

        }
    }
}