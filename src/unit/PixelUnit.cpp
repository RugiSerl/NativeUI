#include "PixelUnit.hpp"
#include "Unit.hpp"
#include "../backend/windows.hpp"
#include <stdexcept>

namespace unit {
    PixelUnit::PixelUnit(float value) : Unit(value) {

    }

    float PixelUnit::GetPixelValue() const {
        return value; // Do nothing here, as it is already in pixel unit.
    }

    float PixelUnit::GetDPIValue() const {
        if (float dpi = backend::GetWindowDPI(); dpi > 0) { // Avoid division by 0.
            return value/dpi;
        } else {
            throw std::runtime_error("Null dpi");
        }
    }
}
