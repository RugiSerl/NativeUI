#pragma once
#include "../properties/Modifier.hpp"
#include "../backend/Rectangle.hpp"
#include <vector>
namespace widget {
    /**
     * Base class for all UI components. Doesn't really do anything on its own.
     * Can also be used as a container.
     */
    class Widget {
    public:
        Widget(property::Modifier modifier = property::Modifier());
        virtual ~Widget() = default;

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
         * Get widget's rectangle on screen with origin from the top left corner.
         */
        backend::Rectangle GetRectangle();

    protected:

        /**
         * Update logic / User input
         */
        virtual void update();

        /**
         * Draw on screen
         */
        virtual void draw();

    private:

        /**
         * Contains all the data passed to the component, like the size, the position, the anchor, ...
         */
        property::Modifier modifier;

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
