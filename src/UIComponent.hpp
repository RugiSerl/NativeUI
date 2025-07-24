#ifndef __UI_COMPONENT__
#define __UI_COMPONENT__
#include "raylib-cpp.hpp"
#include "anchor.hpp"

class UIComponent {
    public:
        UIComponent(raylib::Rectangle r, Anchor2 a);
        void AddChild(UIComponent*);

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
        UIComponent* root; // same
        std::vector<UIComponent> treeStack; // used to know the order of drawing


        bool visible;
        virtual void draw(raylib::Rectangle BoundingBox);
        virtual void update(raylib::Rectangle BoundingBox);

};



#endif