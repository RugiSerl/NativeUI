#pragma once

#include "Panel.hpp"
#include "../shape/Rectangle.hpp"
#include "../backend/inputs.hpp"

namespace widget {
    class PanelTranslatable : public Panel {
    public:
        PanelTranslatable(shape::Shape* shape);
        virtual ~PanelTranslatable() = default;

    protected:
        void update() override;
        void draw() const override;
    };
}
