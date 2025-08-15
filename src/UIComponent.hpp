//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UICOMPONENT_HPP
#define NATIVEUI_UICOMPONENT_HPP
#include "anchor.hpp"
/**
 * Main brick block of the ui system, acts as a node and contains basic information.
 */
class UIComponent
{
public:
    virtual ~UIComponent() = default;

    UIComponent(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor);

    /**
     * Get the coordinates from top lef.
     */
    void GetScreenSpaceRectangoe();

    /**
     * Retrieve a child with an index.
     * @param childIndex index of the child to retrieve.
     * @return the child to retrieve.
     */
    UIComponent* GetChild(int childIndex);

    /**
     * Is the component hovered by the mouse ?
     * @return whether the mouse position is inside the component and no other component is above.
     */
    bool isHovered();

    /**
     * Add a child and set his parent to this.
     * @param child Child to add.
     */
    void AddChild(UIComponent * child);

    raylib::Vector2 position;
    raylib::Vector2 size;
    Anchor2 anchor;

protected:

    /**
     *  Updates component logic with user input.
     */
    virtual void update();

    /**
     *  Draw the component on screen.
     */
    virtual void draw();

private:
    std::vector<UIComponent*> children;
    UIComponent* parent;
};



#endif //NATIVEUI_UICOMPONENT_HPP