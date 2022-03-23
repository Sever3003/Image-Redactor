#include "crop_filter.h"

Crop::Crop(size_t width, size_t height) : width_(width), height_(height) {}

Image Crop::Apply(const Image &image) const {
    size_t new_height = std::max(static_cast<size_t>(0), std::min(image.Height(), height_));
    size_t new_width = std::max(static_cast<size_t>(0), std::min(image.Width(), width_));
    Image image_result = image;
    if (new_height < image.Height()) {
        for (size_t i = 0; i < image.Height() - new_height; ++i) {
            image_result.CutLastRow();
        }
    }
    if (new_width < image.Width()) {
        for (size_t i = 0; i < image.Width() - new_width; ++i) {
            image_result.CutLastColum();
        }
    }
    return image_result;
}