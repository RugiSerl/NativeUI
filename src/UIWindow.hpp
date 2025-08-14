#ifndef __UIWINDOW_H__
#define __UIWINDOW_H__
#include "UIResizablePanel.hpp"
#include "UISplit.hpp"
#include "UIButton.hpp"


#define TOP_BAR_OFFSET 40


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


    /**
     * @brief override normal isBehindChild() since the window is always behind the topBar split.
     * 
     * @param boundingBox 
     * @return whether the window is behind a child or not
     */
    virtual bool isBehindChild(raylib::Rectangle boundingBox);


    /**
     * @brief Add child to window body
     *
     * @param component child
     */
    void AddChild(UIComponent* component) override;

    virtual std::string getType() override;


protected:


    virtual void UpdateAndDraw(raylib::Rectangle boundingBox) override;


private:


    /**
     * @brief splits the window into a top bar and a window body.
     *
     */
    UISplit topBar;


    /**
     * @brief Button to close the window
     *
     */
    UIButton closeButton;

};



#endif