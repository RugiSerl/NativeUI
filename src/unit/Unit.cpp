#include "Unit.hpp"
#include "../backend/windows.hpp"
#include <stdexcept>
namespace unit {
    Unit::Unit(float x) : value(x) {

    }

    float Unit::GetPixelValue() const {
        return value; // Do nothing here, as it is already in pixel unit.
    }

    float Unit::GetDPIValue() const {
        if (float dpi = backend::GetWindowDPI(); dpi > 0) { // Avoid division by 0.
            return value/dpi;
        } else {
            throw std::runtime_error("Null dpi");
        }
    }
}
