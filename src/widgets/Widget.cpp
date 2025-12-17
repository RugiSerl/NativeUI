#include "Widget.hpp"

namespace widget {
    Widget::Widget(shape::Shape* shape) : shape(shape) {

    }

    void Widget::UpdateAndDraw() {
        update();
        draw();
        for (int index : orderOfDrawing) {
            children.at(index)->UpdateAndDraw();
        }
    }

    bool Widget::AddChild(Widget* widget) {
        // Check if child is not already inserted.
        for (Widget* child : children) {
            if (child == widget) {
                return false; // Child is already inserted.
            }
        }
        children.push_back(widget);

        int childrenID = children.size()-1;
        orderOfDrawing.push_back(childrenID);

        return true;
    }

    bool Widget::RemoveChild(Widget* widget) {
        for (int i = 0; i<children.size(); i++) {
            if (children.at(i) == widget) {
                children.erase(children.begin()+i);
                return true;
            }
        }
        return false;
    }

    bool Widget::SetParent(Widget* widget) {
        if (parent != nullptr) {
            return false;
        }
        parent = widget;
        return true;
    }

    shape::Shape* Widget::GetShape() {
        return shape;
    }

    void Widget::update() {
        // Do nothing. Supposed to be overriden by deriving classes
    }

    void Widget::draw() {
        // Do nothing. Supposed to be overriden by deriving classes
    }


}
