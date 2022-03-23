#include "sharpening_filter.h"

Sharpening::Sharpening() : Matrix(SHARP_MATRIX) {}

Image Sharpening::Apply(const Image &image) const {
    return Matrix::Apply(image);
}
