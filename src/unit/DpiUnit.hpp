#pragma once

#include "Unit.hpp"
namespace unit {
    /**
     * A unit that takes in account screen dpi.
     */
    class DpiUnit : public Unit {
    public:
        /**
         * Constructor
         */
        DpiUnit(float value);

        /**
         * Accessors
         */
        float GetPixelValue() const override;
        float GetDPIValue() const override;
    };
}
