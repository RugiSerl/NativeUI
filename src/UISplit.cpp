#include "UISplit.hpp"
#include <iostream>
#include <stdexcept>

UISplit::UISplit(raylib::Rectangle r, Anchor2 a, splitType type, Anchor barAnchor, float barOffset, UIStylebox normalStylebox, UIStylebox selectedStylebox) : UISelectablePanel(r, a, normalStylebox, selectedStylebox), type(type), barOffset(barOffset), firstSide(r, Anchor2{FILL, FILL}), secondSide(r, Anchor2{FILL, FILL}) {
    this->barAnchor = Anchor2 {barAnchor, barAnchor};
    if (type == VERTICAL_SPLIT) {
        this->barAnchor.horizontal = FILL;
    } else {
        this->barAnchor.vertical = FILL;
    }

}
void UISplit::AddChild(UIComponent* child, int side) {
    if (side==0) {
        firstSide.AddChild(child);
    } else if (side==1) {
        secondSide.AddChild(child);
    } else {
        throw std::invalid_argument("side must be 0 or 1");
    }
}

// TODO: not finished
void UISplit::UpdateAndDraw(raylib::Rectangle boundingBox) {

    if (visible) {
        UISelectablePanel::draw(boundingBox);

        raylib::Rectangle anchoredRect = GetAnchoredRect(rect, anchor, boundingBox);
        
        // Draws split bar.
        // Can remove
        GetAnchoredRect(raylib::Rectangle((type==HORIZONTAL_SPLIT)*barOffset, (type==VERTICAL_SPLIT)*barOffset, (type==HORIZONTAL_SPLIT)*BAR_WIDTH, (type==VERTICAL_SPLIT)*BAR_WIDTH), barAnchor, anchoredRect).Draw(LIGHTGRAY);

        if (HORIZONTAL_SPLIT) {
            firstSide.rect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, anchoredRect.width, barOffset);
            secondSide.rect = raylib::Rectangle(anchoredRect.x, anchoredRect.y+barOffset, anchoredRect.width, anchoredRect.height-barOffset);
        } else {
            firstSide.rect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, barOffset, anchoredRect.height);
            secondSide.rect = raylib::Rectangle(anchoredRect.x+barOffset, anchoredRect.y, anchoredRect.width-barOffset, anchoredRect.height);
        }

        
        for (int i = 0 ; i<firstSide.GetChildrenCount(); i++) {
            firstSide.GetChild(i)->UpdateAndDraw(firstSide.rect);
        }
        for (int i = 0 ; i<secondSide.GetChildrenCount(); i++) {
            secondSide.GetChild(i)->UpdateAndDraw(secondSide.rect);
        }
    }
}
