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

    /**
     *
     * @param position relative position of the component from the anchor.
     * @param size Size of the component.
     * @param anchor From which point the component should be positionned.
     */
    Component(raylib::Vector2 position, raylib::Vector2 size, Anchor2 anchor) : position(position), size(size),
                                                                                anchor(anchor), parent(nullptr) {
    };

    /**
     * Get the actual position of the component on screen.
     * @return The rectangle with position from top left
     */
    virtual raylib::Rectangle GetScreenSpaceRectangle() const;

    /**
     * Access the parent in the tree of the component.
     * @return Parent of the component.
     */
    Component *GetParent() const;

    /**
     * Retrieve a child with an index.
     * @param childIndex index of the child to retrieve.
     * @return the child to retrieve.
     */
    Component *GetChild(int childIndex) const;

    /**
     * Allow external access to children, along with GetChild
     * @return The amount of children.
     */
    int GetChildrenCount() const;

    /**
     * Check if the component is colliding with the cursor and if there is no child in front of it.
     * @param mousePosition (optional) the position the cursor.
     * @return whether the mouse position is inside the component and no other component is above.
     */
    bool IsHovered(raylib::Vector2 mousePosition = raylib::Mouse::GetPosition());

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

    void SetRect(raylib::Rectangle rect);

    std::vector<Component *> GetPreOrderWalk();

    Component* GetRoot();
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
