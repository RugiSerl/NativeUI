#ifndef __UI_COMPONENT__
#define __UI_COMPONENT__
#include "raylib-cpp.hpp"
#include "anchor.hpp"

/**
 * @brief Main brick block of the UI. All UI classes extend from it. It allows tree based ui.
 */
class UIComponent {
public:
    /**
     * @brief Construct a new UIComponent object, should generally not be accessed directly
     *
     * @param r rectangle
     * @param a anchor
     * @param parent parent of the node
     * @param root root of the node
     */
    UIComponent(raylib::Rectangle r, Anchor2 a, UIComponent* parent = NULL, UIComponent* root = NULL);
    /**
     * @brief This is the way you add children (you can't access children member)
     *
     * @param child UIComponent to add
     */
    void AddChild(UIComponent* child);

    raylib::Rectangle rect; // be careful ! always apply anchor before using it
    Anchor2 anchor;
    void Hide();
    void Show();
    /**
     * @brief Recursively call update and draw for the component and its children
     * 
     * @param BoundingBox where is contained the object
     */
    virtual void UpdateAndDraw(raylib::Rectangle BoundingBox = GetScreenBoundingbox());
    void RemoveChild(UIComponent* component);
    void RemoveChild(int index);
    int GetChildrenCount();
    UIComponent* GetChild(int index);


protected:
    std::vector<UIComponent*> children;
    UIComponent* parent; // NULL if root of the tree

    // When adding or removing a children, we only do it at the end of the frame to avoid interfering with children updates
    // For that reason I implemented queue based system.
    std::vector<UIComponent*> childrenToRemove;
    std::vector<UIComponent*> childrenToAdd;

    bool visible;
    virtual void draw(raylib::Rectangle BoundingBox);
    virtual void update(raylib::Rectangle BoundingBox);

private:
    /**
     * @brief This the true way of appending child. Don't use it.
     * @warning Use AddChild() instead
     *
     * @param child child to add
     */
    void addChild(UIComponent* child);
    /**
     * @brief This the true way of removing child. Don't use it.
     * @warning Use RemoveChild() instead
     *
     * @param child child to remove
     */
    void removeChild(UIComponent* child);
};



#endif