#pragma once

#include "Widget.hpp"
namespace widget {
    class Panel : public Widget {
    public:
        Panel(shape::Shape* shape);
        ~Panel() override = default;


    protected:

        void update() override;

        void draw() override;

        bool selected;
    };
}
