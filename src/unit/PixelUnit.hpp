#pragma once

#include "Unit.hpp"
namespace unit {
    /**
     * A unit that doesn't take in account screen dpi.
     */
    class PixelUnit : public Unit {
    public:
        /**
         * Constructor
         */
        PixelUnit(float value);

        /**
         * Accessors
         */
        float GetPixelValue() const override;
        float GetDPIValue() const override;
        float GetValue() const;
    };
}
