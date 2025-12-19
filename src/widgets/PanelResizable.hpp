#pragma once

#include "Panel.hpp"
#include "../shape/Rectangle.hpp"
#include "../backend/inputs.hpp"

namespace widget {
    class PanelTransformable : public Panel {
    public:
        PanelTransformable(shape::Rectangle* shape);
        virtual ~PanelTransformable() = default;

    protected:
        virtual void update() override;
    };
}
