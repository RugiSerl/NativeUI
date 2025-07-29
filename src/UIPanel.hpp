#ifndef __UIPANEL_H__
#define __UIPANEL_H__
#include "UIComponent.hpp"
#include "UITheme.hpp"

/**
 * @brief Represents a UIComponent that can be drawn, using stylebox.
 *
 */
class UIPanel : public UIComponent {
public:
    /**
     * @brief Construct a new UIPanel object
     *
     * @param r rectangle of the object
     * @param a anchor of the object
     * @param s stylebox of the object
     */
    UIPanel(raylib::Rectangle r, Anchor2 a, UIStylebox s = DEFAULT_PANEL_STYLEBOX);
    UIStylebox stylebox;
protected:
    virtual void draw(raylib::Rectangle boundingBox) override;

};


#endif