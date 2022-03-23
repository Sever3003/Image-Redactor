#include "image.h"

Image::Image(ImageBody &&body) : body_(body) {}

Image::Image(const ImageBody &body) : body_(body) {}

const Pixel& Image::At(int64_t i, int64_t j) const {
    int y = std::max(static_cast<int64_t>(0), std::min(i, static_cast<int64_t>(body_.size()) - 1));
    int x = std::max(static_cast<int64_t>(0), std::min(j, static_cast<int64_t>(body_[0].size()) - 1));
    return body_[y][x];
}

size_t Image::Height() const {
    return body_.size();
}

size_t Image::Width() const {
    return body_[0].size();
}
void Image::CutLastColum(){
    for (auto& row : body_){
        row.pop_back();
    }
}
void Image::CutLastRow(){
    body_.pop_back();
}
Pixel& Image::At(int64_t i, int64_t j){
    int y = std::max(static_cast<int64_t>(0), std::min(i, static_cast<int64_t>(body_.size()) - 1));
    int x = std::max(static_cast<int64_t>(0), std::min(j, static_cast<int64_t>(body_[0].size()) - 1));
    return body_[y][x];
}
Image::Image(int64_t height, int64_t width): body_(ImageBody(height, std::vector<Pixel>(width))){}