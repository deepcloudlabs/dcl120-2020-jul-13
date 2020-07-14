#pragma once

#include "HotDrink.h"

// abstraction
struct HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() const = 0;
};