//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UICOMPONENT_HPP
#define NATIVEUI_UICOMPONENT_HPP
#include "anchor.hpp"
#include "../include/raylib-cpp.hpp"
/**
 * Main brick block of the ui system, acts as a node and contains basic information.
 */
class Component {
public:
    virtual ~Component() = default;

    Component(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor) : position(position), size(size),
        anchor(anchor), parent(nullptr) {
    };

    /**
     * Get the actual position of the component on screen.
     * @return The rectangle with position from top left
     */
    raylib::Rectangle GetScreenSpaceRectangle() const;

    /**
     * Retrieve a child with an index.
     * @param childIndex index of the child to retrieve.
     * @return the child to retrieve.
     */
    Component *GetChild(int childIndex) const;

    /**
     * Is the component hovered by the mouse ?
     * @return whether the mouse position is inside the component and no other component is above.
     */
    bool isHovered();

    /**
     * Add a child and set his parent to this.
     * @param child Child to add.
     */
    void AddChild(Component *child);

    /**
     * Removes a child
     * @param child Child to remove.
     */
    void RemoveChild(Component *child);

    /**
     * Recursively call update and draw of itself then its children.
     */
    void UpdateAndDraw();

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
    std::vector<Component *> children;
    Component *parent;
};


#endif //NATIVEUI_UICOMPONENT_HPP
