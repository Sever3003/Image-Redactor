#include "matrix.h"

Matrix::Matrix(const MatrixBody &matrix_body) {
    size_t i = 0;
    body_.resize(matrix_body.size());
    for (const auto &row: matrix_body) {
        body_[i].reserve(row.size());
        for (const auto &elem: row) {
            body_[i].push_back(elem);
        }
        ++i;
    }
}

#include <iostream>

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>> &other) {
    size_t i = 0;
    body_.resize(other.size());
    for (const auto &row: other) {
        body_[i].reserve(row.size());
        for (const auto &elem: row) {
            body_[i].push_back(elem);
        }
        ++i;
    }
}

Image Matrix::Apply(const Image &image) const {
    Image image_result = image;
    int height = body_.size() / 2;
    int width = body_[0].size() / 2;

    for (int i = 0; i < image.Height(); ++i) {
        for (int j = 0; j < image.Width(); ++j) {
            double green = 0;
            double red = 0;
            double blue = 0;
            for (int coef_i = -1 * height; coef_i <= 1 * height; ++coef_i) {
                for (int coef_j = -1 * width; coef_j <= 1 * width; ++coef_j) {
                    green += body_[coef_i + height][coef_j + width] *
                             static_cast<double>(image.At(i + coef_i, j + coef_j).green);
                    red += body_[coef_i + height][coef_j + width] *
                           static_cast<double>(image.At(i + coef_i, j + coef_j).red);
                    blue += body_[coef_i + height][coef_j + width] *
                            static_cast<double>(image.At(i + coef_i, j + coef_j).blue);
                }
            }
            image_result.At(i, j).green = green;
            image_result.At(i, j).blue = blue;
            image_result.At(i, j).red = red;
        }
    }
    return image_result;
}


Matrix &Matrix::operator=(const MatrixBody &body) {
    body_ = body;
    return *this;
}

Matrix &Matrix::operator=(MatrixBody &&body) {
    body_ = body;
    return *this;
}