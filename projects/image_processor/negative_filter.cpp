#include "negative_filter.h"

Image Negative::Apply(const Image &image) const {
    Image image_result = image;
    for (size_t i = 0; i < image_result.Height(); ++i) {
        for (size_t j = 0; j < image_result.Width(); ++j) {
            image_result.At(i, j).blue = 255 - image.At(i, j).blue;
            image_result.At(i, j).green = 255 - image.At(i, j).green;
            image_result.At(i, j).red = 255 - image.At(i, j).red;
        }
    }
    return image_result;
}