#include "DpiUnit.hpp"
#include "Unit.hpp"
#include "../backend/windows.hpp"

namespace unit {
    DpiUnit::DpiUnit(float value) : Unit(value) {

    }

    float DpiUnit::GetPixelValue() const {
        return value * backend::GetWindowDPI();
    }

    float DpiUnit::GetDPIValue() const {
        return value;
    }

    float DpiUnit::GetValue() const {
        return value;
    }
}
