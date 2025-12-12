#pragma once
#include "../properties/Modifier.hpp"
#include "../shape/Shape.hpp"
#include <vector>
namespace widget {
    /**
     * Base class for all UI components. Doesn't really do anything on its own.
     * Can also be used as a container.
     */
    class Widget {
    public:
        Widget(property::Modifier modifier, shape::Shape* shape);
        virtual ~Widget() {
            delete shape;
        };

        /**
         * updates and draws widget, and recursively updates and draws its children.
         */
        void UpdateAndDraw();

        /**
         * Adds widget as a child.
         * Returns whether child could be added.
         */
        bool AddChild(Widget* widget);

        /**
         * Removes widget from children.
         * Returns whether child was removed.
         */
        bool RemoveChild(Widget* widget);

        /**
         * Set widget as parent
         */
        bool SetParent(Widget* widget);

        /**
         * Get widget's rectangle on screen with origin from the top left corner.
         */
        shape::Shape* GetShape();

    protected:

        /**
         * Update logic / User input
         */
        virtual void update();

        /**
         * Draw on screen
         */
        virtual void draw();

        /**
         * Contains all the data passed to the component, like the size, the position, the anchor, ...
         */
        property::Modifier modifier;

        /**
         * Shape of the widget. Also defines its collision shape.
         */
        shape::Shape* shape;

    private:

        /**
         * Children of the widget. They are constrained within the rectangle of the widget.
         */
        std::vector<Widget*> children;

        /**
         * Keeping track of which components are above each ones.
         */
        std::vector<int> orderOfDrawing;

        /**
         * nullptdr if root of the tree.
         */
        Widget* parent;


    };
}
