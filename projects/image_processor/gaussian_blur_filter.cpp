#include "gaussian_blur_filter.h"

GaussianBlur::GaussianBlur(double sigma){
    Matrix::MatrixBody gausian_body(7, std::vector<double>(7));

    double sum = 0;
    for (int x = -3; x <= 3; ++x) {
        for (int y = -3; y <= 3; ++y) {
            double distance = x * x + y * y;
            gausian_body[x + 3][y + 3] = (exp(-(distance * distance) / sigma)) / (M_PI * sigma);
            sum += gausian_body[x + 3][y + 3];
        }
    }
    for (int x = -3; x <= 3; ++x) {
        for (int y = -3; y <= 3; ++y) {
            gausian_body[x + 3][y + 3] /= sum;
        }
    }
    dynamic_cast<Matrix&>(*this) = gausian_body;
}

Image GaussianBlur::Apply(const Image &image) const {
    return Matrix::Apply(image);
}
