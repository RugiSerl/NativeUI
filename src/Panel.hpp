//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UIPANEL_HPP
#define NATIVEUI_UIPANEL_HPP
#include <cassert>

#include "Component.hpp"
#include "StyleBox.hpp"
#include "Theme.hpp"

/**
 * Basic box shown on screen and with drawing priorities on which was selected last.
 */
class Panel : public Component {
public:
    Panel(Modifier modifier, LayoutType layout, bool selectable = false);

    ~Panel() override = default;

    virtual void update() override;

    virtual void draw() override;

protected:
    // Can the panel be selected on click
    bool selectable;

    // State of selection.
    bool selected;

    // Default styleBox.
    StyleBox style = DEFAULT_STYLE;

    // StyleBox when the user has selected the component.
    StyleBox selectedStyle = DEFAULT_SELECTED_STYLE;
};


#endif //NATIVEUI_UIPANEL_HPP
