#include "hexagonal_pixel.h"


Hexagonal::Hexagonal(int radius){
    Matrix::MatrixBody hexagonal_body(radius * 2 + 1, std::vector<double>(radius * 2 + 1, 0));
    int64_t sum = 0;
    int third_part = (hexagonal_body.size() / 3);
    for (size_t i = 0; i < third_part; ++i) {
        for (size_t j = third_part - i; j < 2 * third_part + i; ++j) {
            hexagonal_body[i][j] = 255;
            sum += 255;
        }
    }
    for (size_t i = third_part; i < 2 * third_part; ++i) {
        for (size_t j = 0; j < hexagonal_body.size(); ++j) {
            hexagonal_body[i][j] = 255;
            sum += 255;
        }
    }
    for (int i = 0; i < third_part; ++i) {
        for (int j = i; j < hexagonal_body.size() - i; ++j) {
            hexagonal_body[i][j] = 255;
            sum += 255;
        }
    }
    for (size_t i = 0; i < hexagonal_body.size(); ++i) {
        for (size_t j = 0; j < hexagonal_body[0].size(); ++j) {
            hexagonal_body[i][j] = hexagonal_body[i][j] / sum;
        }
    }
    dynamic_cast<Matrix&>(*this) = hexagonal_body;
}


Image Hexagonal::Apply(const Image &image) const {
    return Matrix::Apply(image);
}
