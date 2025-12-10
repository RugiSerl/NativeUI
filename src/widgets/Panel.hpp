#pragma once

#include "Widget.hpp"
#include "../style/Stylebox.hpp"
namespace widget {
    class Panel : public Widget {
    public:
        Panel(property::Modifier modifier = property::Modifier(), style::StyleBox styleBox = style::StyleBox());

    protected:

        void update() override;

        void draw() override;

    private:
        style::StyleBox styleBox;
    };
}
