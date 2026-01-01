#pragma once

namespace unit {
    /**
     * Abstract class representing a unit.
     */
    class Unit {
    public:
        /**
         * Constructor
         */
        Unit(float x);

        /**
         * Accessors
         */
        virtual float GetPixelValue() const = 0;
        virtual float GetDPIValue() const = 0;
    protected:
        float value;
    };
}
