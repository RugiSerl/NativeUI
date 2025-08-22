//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UIPANEL_HPP
#define NATIVEUI_UIPANEL_HPP
#include <cassert>

#include "Component.hpp"
#include "StyleBox.hpp"
#include "Theme.hpp"

class Panel : public Component {
public:
    Panel(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor,
          bool selectable = false) : Component(position, size, anchor),
                                     selectable(selectable), selected(false) {
        assert(size.x >= 0 && size.y >= 0 && "Panel() : The width and the height of the component must be positive");
    };

    ~Panel() override = default;

    virtual void update() override;

    virtual void draw() override;

protected:
    /**
     * Move the component to put it above its siblings.
     */
    void moveToFront();

    bool selectable;

    bool selected;

    StyleBox style = DEFAULT_STYLE;

    StyleBox selectedStyle = DEFAULT_SELECTED_STYLE;
};


#endif //NATIVEUI_UIPANEL_HPP
