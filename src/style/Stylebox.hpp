#pragma once
#include "../backend/Color.hpp"
#include "../backend/Rectangle.hpp"

namespace style {
    /**
     * Describes draw parameter of a 2d rectangle.
     */
    class StyleBox {
    public:
        StyleBox(float cornerRadius, float borderwidth, backend::Color fillColor, backend::Color borderColor);

        /**
         * Defaults everything to 0.
         */
        StyleBox() = default;

        /**
         * Render the StyleBox on screen. 
         */
        void Render(backend::Rectangle target);
    protected:
        /**
         * StyleBox properties
         */
        float cornerRadius, borderwidth;
        backend::Color fillColor, borderColor;

    };
}
