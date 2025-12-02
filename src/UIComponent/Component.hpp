//
// Created by raphael on 8/15/25.
//

#ifndef NATIVEUI_COMPONENT_HPP
#define NATIVEUI_COMPONENT_HPP
#include "../Properties/Layout.hpp"
#include "../Properties/Modifier.hpp"
#include "../math/rectangle.hpp"

#include "raylib-cpp.hpp"

namespace UIComponent {
    /**
     * @brief Main brick block of the ui system, acts as a node and contains basic information.
     */
    class Component {
    public:
        virtual ~Component() = default;

        /**
         * @param modifier transformations properties.
         * @param layout describes how a component should draw its children
         */
        Component(Modifier modifier, LayoutType layout);

        /**
         * @brief Get the actual position of the component on screen.
         * @return The rectangle with position from top left.
         */
        virtual math::Rectangle GetScreenSpaceRectangle() const;

        /**
         * @brief Shortcut for GetParent().GetScreenSpaceRectangle().
         * @return The rectangle of the parent component in screen space coordinates.
         */
        math::Rectangle GetParentRectangle() const;

        /**
         * @brief Shortcut for GetParent()->layout, except it checks if parent is null before.
         * @return Get the parent layout
         */
        LayoutType GetParentLayout() const;

        /**
         * Access the parent in the tree of the component.
         * @return Parent of the component.
         */
        Component *GetParent() const;

        /**
         * @brief Get rectangle of the previous sibling. If the component does not have previous sibling, it will return the
         * parent's rectangle
         * @return the rectangle of the previous sibling.
         */
        math::Rectangle GetPreviousSiblingRectangle() const;

        /**
         * @brief Get previous sibling in the tree.
         * @return The previous sibling in the order of the children of the parent. Returns nullptr if the component is the first child.
         */
        Component *GetPreviousSiblingByInsertionOrder() const;

        /**
         * Retrieve a child with an index.
         * @param childIndex index of the child to retrieve.
         * @return the child to retrieve.
         */
        Component *GetChild(int childIndex) const;

        /**
         * @brief retrieve child index by its instance. Returns in the order of insertion. @related childrenOrderedByInsertion
         * @param child Instance.
         * @return Index of child. -1 if the instance was not found.
         */
        int GetChildIndexInsertion(const Component *child) const;

        /**
         * @brief retrieve child index by its instance. Returns in the order of draw. @related childrenOrderedByDraw
         * @param child Instance
         * @return Index of child. -1 if the instance was not found.
         */
        int GetChildIndexDraw(const Component *child) const;

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
        bool IsHovered(math::Vector2 mousePosition = raylib::Mouse::GetPosition());

        /**
         * Add a child and set his parent to this.
         * @param child Child to add.
         */
        virtual void AddChild(Component *child);

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
        void SetRect(math::Rectangle rect);

        /**
         * @brief Get pre-order walk in the component children tree.
         * @return Vector containing the pre-order walk.
         */
        std::vector<Component *> GetPreOrderWalk();

        /**
         * @brief Result of GetParent(), until the parent is null.
         * @return Root of the component tree.
         */
        Component *GetRoot();

        /**
         * Set visible as false.
         */
        void Hide();

        /**
         * Set visible as true.
         */
        void Show();

        /**
         * Set passive to true.
         */
        void MakePassive();

        /**
         * Set passive to false.
         */
        void MakeActive();


    protected:
        /**
         *  Updates component logic with user input.
         */
        virtual void update();

        /**
         *  Draw the component on screen.
         */
        virtual void draw();

        /**
         *  Makes this component the first in its parent's childrenOrderedByDraw
         */
        void MoveToFront();


        Modifier modifier;

        LayoutType layout;

    private:
        // Children of the component, allowing tree structure.
        // Here we have two collection of children, having both the exact same components, but with different ordering.

        // Children ordered by the order of draw, ie the first is the first children being drawn and so on.
        // It may change when component are brought to the foreground when selected for instance.
        std::vector<Component *> childrenOrderedByInsertion;

        // Children ordered by when it got inserted as a child.
        // It will not change unless change is made to the tree
        std::vector<Component *> childrenOrderedByDraw;

        // nullptr if root of the tree. Else points to the component that has this component as a child.
        Component *parent;

        /**
         * Defines if component must be taken in account when
         * calculating collision with mouse, such has when
         * detecting if component is being hovered.
         * @note This does not affect children.
         */
        bool passive;

        /**
         * Defines if component, and its children, are visible.
         * @note This also impact whether component are updated.
         */
        bool visible;
    };


}

#endif //NATIVEUI_UICOMPONENT_HPP
