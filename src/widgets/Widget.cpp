#include "Widget.hpp"
#include "../backend/inputs.hpp"
#include <vector>

namespace widget {
    Widget::Widget(shape::Shape* shape) : shape(shape), parent(nullptr) {

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
        widget->SetParent(this);

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

    Widget* Widget::GetParent() {
        return parent;
    }

    Widget* Widget::GetRoot() {
        return (parent==nullptr) ? this : parent->GetRoot();
    }

    shape::Shape* Widget::GetShape() {
        return shape;
    }

    coordinates::ScreenRectangle Widget::GetContainingRectangle() const {
        return (parent == nullptr) ? backend::GetWindowRect() : parent->GetScreenRectangle();
    }

    coordinates::ScreenRectangle Widget::GetScreenRectangle() const {
        return shape->GetScreenRectangle(GetContainingRectangle());
    }

    bool Widget::IsHovered(coordinates::ScreenCoordinate mousePosition) {
        std::vector<Widget*> allTheWidgets = GetRoot()->GetChildrenRecursive();

        // Looping in the reverse order, because the last widgets are the last to be drawn and so are above the others.
        for (int i = allTheWidgets.size()-1; i>=0; i--) {
            if (allTheWidgets[i]->GetShape()->GetPointCollision(allTheWidgets[i]->GetContainingRectangle(), mousePosition)) {
                return this == allTheWidgets[i]; // Is this widget the one being hovered ?
            }
        }
        // This should actually never happen.
        return false;
    }

    std::vector<Widget*> Widget::GetChildrenRecursive() {
        // Here we return the entirety of the children of a node by performing a pre order walk of the widget tree.
        std::vector<Widget*> preOrderWalk = {this};
        for (int childIndex = 0; childIndex<children.size(); childIndex++) {
            std::vector<Widget*> childPreOrderWalk = children[orderOfDrawing[childIndex]]->GetChildrenRecursive();

            // Inserting into preOrderWalk childPreOrderWalk.
            preOrderWalk.insert(preOrderWalk.end(), childPreOrderWalk.begin(), childPreOrderWalk.end());
        }
        return preOrderWalk;
    }

    void Widget::update() {
        // Do nothing. Supposed to be overriden by deriving classes
    }

    void Widget::draw() const {
        // Do nothing. Supposed to be overriden by deriving classes
    }


}
