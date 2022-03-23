#pragma once


#include "pixel.h"
#include <cmath>
#include "image.h"

class Filter {
public:
    virtual Image Apply(const Image &image) const = 0;
};


