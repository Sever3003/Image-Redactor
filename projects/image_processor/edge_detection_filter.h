#pragma once

#include "matrix.h"
#include "grayscale_filter.h"

const Matrix EDGE_DETECTION_MATRIX = {{0,  -1, 0},
                                      {-1, 4,  -1},
                                      {0,  -1, 0}};
class Threshold : virtual public Filter{
public:
    Threshold(double threshold);
    Image Apply(const Image &image) const override;
private:
    double threshold_;
};

class EdgeDetection : public Grayscale, public Matrix, public Threshold{
public:
    EdgeDetection(double threshold);

    Image Apply(const Image &image) const override;
};

