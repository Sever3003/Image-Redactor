#include "grayscale_filter.h"

uint8_t Grayscale::Calculate(const Pixel &pixel) const {
    return static_cast<uint8_t>(0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue);

}

Image Grayscale::Apply(const Image &image) const {
    Image image_result = image;
    for (size_t i = 0; i < image_result.Height(); ++i) {
        for (size_t j = 0; j < image_result.Width(); ++j) {
            image_result.At(i, j).blue = Calculate(image.At(i, j));
            image_result.At(i, j).green = Calculate(image.At(i, j));
            image_result.At(i, j).red = Calculate(image.At(i, j));
        }
    }
    return image_result;
}