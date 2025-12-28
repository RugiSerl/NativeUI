#pragma once

namespace unit {
    /**
     * Class representing a unit.
     * Default (base class) is pixel unit.
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
        virtual float GetPixelValue() const;
        virtual float GetDPIValue() const;
    protected:
        float value;
    };
}
