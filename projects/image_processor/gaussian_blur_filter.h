#pragma once

#include "matrix.h"

class GaussianBlur : public Matrix  {
public:
    GaussianBlur(double sigma);

    Image Apply(const Image &image) const override;
};


