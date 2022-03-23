#pragma once

#include "filter.h"

class Negative : virtual public Filter {
public:
    Image Apply(const Image &image) const override;
};

