#ifndef __UI_COMPONENT__
#define __UI_COMPONENT__
#include "raylib-cpp.hpp"
#include "anchor.hpp"

/**
 * Main brick block of the UI. All UI classes extend from it. It allows tree based ui.
 */
class UIComponent {
public:
    UIComponent(raylib::Rectangle r, Anchor2 a, UIComponent* parent = NULL, UIComponent* root = NULL);
    void AddChild(UIComponent* child);

    raylib::Rectangle rect; // be careful ! always apply anchor before using it
    Anchor2 anchor;
    void Hide();
    void Show();
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
    void addChild(UIComponent* child);
    void removeChild(UIComponent* child);
};



#endif