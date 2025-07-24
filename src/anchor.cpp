#include "anchor.hpp"
#include <iostream>

raylib::Rectangle GetScreenBoundingbox() {
    return raylib::Rectangle(0, 0, GetScreenWidth(), GetScreenHeight());
}

raylib::Rectangle GetAnchoredRect(raylib::Rectangle rect, Anchor2 anchor, raylib::Rectangle boundingBox) {
    raylib::Rectangle res(rect.GetSize());
    switch (anchor.horizontal)
    {
    case LEFT:
        res.x = boundingBox.x + rect.x;
        break;
    case RIGHT:
        res.x = boundingBox.x + boundingBox.width - rect.width - rect.x;
        break;
    case CENTER:
        res.x = boundingBox.x + boundingBox.width/2.0f - rect.width/2.0f + rect.x;
        break;
    case FILL:
        res.x = boundingBox.x; 
        res.width = boundingBox.width;
        break;
    default:
        std::cerr << "Incorrect value for horizontal anchor" << std::endl;
    }

    switch (anchor.vertical)
    {
    case TOP:
        res.y = boundingBox.y + rect.y;
        break;
    case BOTTOM:
        res.y = boundingBox.y + boundingBox.height - rect.height - rect.y;
        break;
    case CENTER:
        res.y = boundingBox.y + boundingBox.height/2.0f - rect.height/2.0f + rect.y;
        break;
    case FILL:
        res.y = boundingBox.y; 
        res.height = boundingBox.height;
        break;
        
    default:
        std::cerr << "Incorrect value for vertical anchor" << std::endl;
    }
    return res;
}

raylib::Rectangle GetAnchoredRect(raylib::Rectangle rect, Anchor2 anchor) {
    return GetAnchoredRect(rect, anchor, GetScreenBoundingbox());
}