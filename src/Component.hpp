//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_UICOMPONENT_HPP
#define NATIVEUI_UICOMPONENT_HPP
#include "anchor.hpp"
#include "Layout.hpp"
#include "Modifier.hpp"
#include "../include/raylib-cpp.hpp"
/**
 * @brief Main brick block of the ui system, acts as a node and contains basic information.
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
    Component(Modifier modifier, LayoutType layout) : modifier(modifier), parent(nullptr), layout(layout) {
    }
    ;

    /**
     * @brief Get the actual position of the component on screen.
     * @return The rectangle with position from top left.
     */
    virtual raylib::Rectangle GetScreenSpaceRectangle() const;

    /**
     * @brief Shortcut for GetParent().GetScreenSpaceRectangle().
     * @return The rectangle of the parent component in screen space coordinates.
     */
    raylib::Rectangle GetParentRectangle() const;

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
     * Allow external access to children, along with GetChild().
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
     * @brief Removes a child.
     * @param child Child to remove.
     */
    void RemoveChild(Component *child);

    /**
     * @brief Recursively call update and draw of itself then its children.
     */
    void UpdateAndDraw();

    /**
     * @brief No need to explain.
     * @param rect Component's rect.
     */
    void SetRect(raylib::Rectangle rect);

    /**
     * @brief Get pre-order walk in the component children tree.
     * @return Vector containing the pre-order walk.
     */
    std::vector<Component *> GetPreOrderWalk();

    /**
     * @brief Result of GetParent(), until the parent is null.
     * @return Root of the component tree.
     */
    Component* GetRoot();

    Modifier modifier;

    LayoutType layout;



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

    // Children of the component, allowing tree structure.
    std::vector<Component *> children;

    // nullptr if root of the tree. Else points to the component that has this component as a child.
    Component *parent;
};


#endif //NATIVEUI_UICOMPONENT_HPP
