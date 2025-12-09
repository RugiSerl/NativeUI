#pragma once
#include "../properties/Modifier.hpp"
#include <vector>
namespace widget {
    /**
     * Base class for all UI components.
     */
    class Widget {
    public:
        Widget(property::Modifier modifier);

        /**
         * updates and draws widget, and recursively updates and draws its children.
         */
        void UpdateAndDraw();

    protected:

        /**
         * Update logic / User input
         */
        void update();

        /**
         * Draw on screen
         */
        void draw();

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
