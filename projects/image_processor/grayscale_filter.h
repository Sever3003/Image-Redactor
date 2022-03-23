#pragma once

#include "filter.h"


class Grayscale : virtual public Filter {
public:
    Image Apply(const Image &image) const;
private:
    uint8_t Calculate(const Pixel& pixel) const;
};

