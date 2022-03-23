#pragma once

#include "matrix.h"

class Hexagonal : virtual public Matrix {
public:
    Hexagonal(int radius);

    Image Apply(const Image &image) const override;
};

