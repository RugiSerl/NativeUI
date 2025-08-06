#ifndef __UIRESIZABLEPANEL_H__
#define __UIRESIZABLEPANEL_H__
#include "UITranslatablePanel.hpp"

#define RESIZE_LENIENCY 10

/**
 * @brief Contains information of which edge can be resized.
 *
 */
class resizableDirections {
public:
    resizableDirections() : Top(false), Bottom(false), Left(false), Right(false) {};
    resizableDirections(bool value) : Top(value), Bottom(value), Left(value), Right(value) {};
    resizableDirections(bool top, bool bottom, bool right, bool left) : Top(top), Bottom(bottom), Left(left), Right(right) {};
    bool isNone() {
        return !(Top || Bottom || Left || Right);
    };
    void SetToNone() {
        Top = false;
        Bottom = false;
        Left = false;
        Right = false;
    };
    bool Top;
    bool Bottom;
    bool Left;
    bool Right;
};

/**
 * @brief A panel you can resize by dragging the edges.
 */
class UIResizablePanel : public UITranslatablePanel {
public:


    /**
     * @brief Construct a new UIResizablePanel object
     *
     * @param r rectangle of the object
     * @param resizableConstraints constraint you want to impose to resize edges
     * @param minSize The minimum size of the rectangle
     * @param normalStylebox
     * @param selectedStylebox
     */
    UIResizablePanel(raylib::Rectangle r, resizableDirections resizableConstraints, Vector2 minSize = raylib::Vector2(0, 0), UIStylebox normalStylebox = DEFAULT_PANEL_STYLEBOX, UIStylebox selectedStylebox = DEFAULT_SELECTED_STYLEBOX) : UITranslatablePanel(r, normalStylebox, selectedStylebox), resizableConstraints(resizableConstraints), minSize(minSize) {};


protected:


    /**
     * @brief setup before translation
     *
     * @param boundingBox needed to get rect absolute position
     */
    void startResizing(raylib::Rectangle boundingBox);


    /**
     * @brief Update variables during translation
     *
     * @param boundingBox
     */
    void updateResizing(raylib::Rectangle boundingBox);


    /**
     * @brief finalize translation
     *
     */
    void stopResizing();

    virtual void update(raylib::Rectangle boundingBox) override;

private:
    Vector2 minSize;
    resizableDirections resizeState;
    resizableDirections resizableConstraints;
};


#endif // !__UIRESIZABLEPANEL_H__