#ifndef __UIWINDOW_H__
#define __UIWINDOW_H__
#include "UIResizablePanel.hpp"
#include "UISplit.hpp"

class UIWindow : public UIResizablePanel {
public:


    /**
     * @brief Construct a new UIWindow object
     *
     * @param r rectangle of the object
     * @param resizableConstraints constraint you want to impose to resize edges
     * @param minSize The minimum size of the rectangle
     * @param normalStylebox
     * @param selectedStylebox
     */
    UIWindow(raylib::Rectangle r, resizableDirections resizableConstraints, Vector2 minSize = raylib::Vector2(0, 0), UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX);

    
    void AddChild(UIComponent* component) override;

    
protected:
    virtual void UpdateAndDraw(raylib::Rectangle boundingBox) override;

private:
    UISplit topBar;

};



#endif