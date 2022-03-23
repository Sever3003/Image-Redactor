#include "edge_detection_filter.h"


Threshold::Threshold(double threshold) : threshold_(threshold) {}

Image Threshold::Apply(const Image &image) const {
    auto image_result = image;
    for (size_t i = 0; i < image_result.Height(); ++i) {
        for (size_t j = 0; j < image_result.Width(); ++j) {
            auto pixel = image_result.At(i, j);
            if ((static_cast<int>(pixel.blue) + static_cast<int>(pixel.green) + static_cast<int>(pixel.red)) <
                threshold_ * 255) {
                image_result.At(i, j) = {0, 0, 0};
            } else {
                image_result.At(i, j) = {255, 255, 255};
            }
        }
    }
    return image_result;
}

EdgeDetection::EdgeDetection(double threshold) : Matrix(EDGE_DETECTION_MATRIX), Threshold(threshold) {}

Image EdgeDetection::Apply(const Image &image) const {
    auto image_result = Grayscale::Apply(image);
    image_result = Matrix::Apply(image_result);
    return Threshold::Apply(image_result);
}
