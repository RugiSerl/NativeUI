#ifndef __UISELECTABLEPANEL_H__
#define __UISELECTABLEPANEL_H__
#include "UIStylebox.hpp"
#include "UIPanel.hpp"

/**
 * @brief A Panel selectable when clicked upon, and handling overlapping with other selectable panels.
 */
class UISelectablePanel : public UIPanel {
public:


    /**
     * @brief Construct a new UISelectablePanel object
     *
     * @param r rectangle of the object
     * @param a anchor of the object
     * @param normalStylebox
     * @param selectedStylebox
     */
    UISelectablePanel(raylib::Rectangle r, Anchor2 a, UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX);


    /**
     * @brief Is the panel selected ?
     */
    bool IsSelected();


    /**
     * @brief if panel is behind one of its child at the mouse position
     */
    bool isBehindChild(raylib::Rectangle boundingBox);


    virtual std::string getType() override;


protected:


    /**
     * @brief Get if panel is colliding with extra steps :
     * First making sure that no sibling is overlapping in front of it,
     * Then make sure that no children is in front of it.
     *
     * @param boundingBox
     * @return whether the panel is selectable.
     */
    bool getMouseCollision(raylib::Rectangle boundingBox);
    virtual void update(raylib::Rectangle boundingBox) override;
    virtual void draw(raylib::Rectangle boundingBox) override;


    /**
     * @brief Will deselect other panels.
     *
     */
    void onSelected();


    bool selected;
    UIStylebox selectedStylebox;

};


#endif