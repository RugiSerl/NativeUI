#ifndef __UIPANEL_H__
#define __UIPANEL_H__
#include "UIComponent.hpp"
#include "UITheme.hpp"

/**
 * Represents a UIComponent that can be drawn, using stylebox.
 */
class UIPanel : public UIComponent {
public:
    UIPanel(raylib::Rectangle r, Anchor2 a, UIStylebox s = DEFAULT_PANEL_STYLEBOX);
    UIStylebox stylebox;
protected:
    virtual void draw(raylib::Rectangle boundingBox) override;

};


#endif