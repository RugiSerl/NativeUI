#include "UISplit.hpp"
#include <iostream>
#include <stdexcept>
#include "utils.hpp"

UISplit::UISplit(raylib::Rectangle r, Anchor2 a, splitType type,
                 Anchor barAnchor, float barOffset, UIStylebox normalStylebox,
                 UIStylebox selectedStylebox)
    : UISelectablePanel(r, a, normalStylebox, selectedStylebox), type(type), barOffset(barOffset) {

    this->barAnchor = Anchor2{barAnchor, barAnchor};

    if (type == VERTICAL_SPLIT) {
        this->barAnchor.horizontal = FILL;

    } else {
        this->barAnchor.vertical = FILL;
    }

    this->children.push_back(new UISelectablePanel(raylib::Rectangle(0), Anchor2{FILL, FILL}));
    this->children.push_back(new UISelectablePanel(raylib::Rectangle(0), Anchor2{FILL, FILL}));
    this->children.at(0)->SetParent(this);
    this->children.at(1)->SetParent(this);

}
void UISplit::AddChild(UIComponent *child, int side) {
    if (side == 0 || side == 1) {
        this->children.at(side)->AddChild(child);

    } else {
        throw std::invalid_argument("side must be 0 or 1");
    }
}



void UISplit::UpdateAndDraw(raylib::Rectangle boundingBox) {
    if (visible) {

        
        UISelectablePanel::draw(boundingBox);

        

        this->children.at(0)->UpdateAndDraw(this->GetSplittedRectangle(boundingBox, 0));
        this->children.at(1)->UpdateAndDraw(this->GetSplittedRectangle(boundingBox, 1));

        // Draws split bar.
        // // Can remove
        // GetAnchoredRect(raylib::Rectangle((type == HORIZONTAL_SPLIT) * barOffset,
        //                                   (type == VERTICAL_SPLIT) * barOffset,
        //                                   (type == HORIZONTAL_SPLIT) * BAR_WIDTH,
        //                                   (type == VERTICAL_SPLIT) * BAR_WIDTH),
        //                 barAnchor, anchoredRect)
        // .Draw(LIGHTGRAY);
    }
}

raylib::Rectangle UISplit::GetSplittedRectangle(raylib::Rectangle boundingBox, int side) {

    raylib::Rectangle anchoredRect = GetScreenSpaceCoordinate(boundingBox);

    raylib::Rectangle firstSideRect;
    raylib::Rectangle secondSideRect;

    if (type == VERTICAL_SPLIT) {
        firstSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, anchoredRect.width, barOffset);
        secondSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y + barOffset, anchoredRect.width, anchoredRect.height - barOffset);

    } else {
        firstSideRect = raylib::Rectangle(anchoredRect.x, anchoredRect.y, barOffset, anchoredRect.height);
        secondSideRect = raylib::Rectangle( anchoredRect.x + barOffset, anchoredRect.y, anchoredRect.width - barOffset, anchoredRect.height);
    }

    return (side==0)?firstSideRect : secondSideRect;
}

bool UISplit::IsSelected(int side) {
    if (side == 0) return firstSide->IsSelected();

    if (side == 1) return secondSide->IsSelected();

    return 0;
}

std::string UISplit::getType() {
    return "UISplit";
}

