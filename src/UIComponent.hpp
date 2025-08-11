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
     * @brief This is the way you add children (you can't access children member). This takes effect at the UpdateAndDraw() function
     *
     * @param child UIComponent to add
     */
    virtual void AddChild(UIComponent* child);


    /**
     * @brief Recursively call update and draw for the component and its children. This takes effect at the UpdateAndDraw() function
     *
     * @param BoundingBox where is contained the object
     */
    virtual void UpdateAndDraw(raylib::Rectangle BoundingBox = GetScreenBoundingbox());


    /**
     * @brief Remove child with child pointer value
     *
     * @param component child
     */
    void RemoveChild(UIComponent* component);


    /**
     * @brief remove child with index value
     *
     * @param index childIndex
     */
    void RemoveChild(int index);




    /**
     * @brief Set the Parent object
     * 
     * @param parent 
     */
    void SetParent(UIComponent* parent);



    /**
     * @brief Hide the component (and its children)
     *
     */
    void Hide();


    /**
     * @brief Show the component (and its children)
     *
     */
    void Show();


    virtual std::vector<UIComponent*> GetChildren();


    raylib::Rectangle rect; // be careful ! always apply anchor before using it
    Anchor2 anchor;

protected:


    /**
     * @brief Draw the component on screen. Mostly overriden by children classes
     *
     * @param BoundingBox bounds to restrain to, often the rectangle of the parent
     */
    virtual void draw(raylib::Rectangle BoundingBox);


    /**
     * @brief Update component logic. Mostly overriden by children classes
     *
     * @param BoundingBox bounds to restrain to, often the rectangle of the parent
     */
    virtual void update(raylib::Rectangle BoundingBox);


    std::vector<UIComponent*> children;
    UIComponent* parent; // NULL if root of the tree

    // When adding or removing a children, we only do it at the end of the frame to avoid interfering with children updates
    // For that reason I implemented queue based system.
    std::vector<UIComponent*> childrenToRemove;
    std::vector<UIComponent*> childrenToAdd;

    bool visible;
    ;

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