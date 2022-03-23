#pragma once

#include "matrix.h"

const Matrix SHARP_MATRIX = {{0,  -1, 0},
                             {-1, 5,  -1},
                             {0,  -1, 0}};

class Sharpening : virtual public Matrix {
public:
    Sharpening();
    Image Apply(const Image &image) const override;

};

