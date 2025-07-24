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
        void AddChild(UIComponent*);
        void SetAsChild(UIComponent* parent);

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
        UIComponent* root;

        bool visible;
        virtual void draw(raylib::Rectangle BoundingBox);
        virtual void update(raylib::Rectangle BoundingBox);

};



#endif