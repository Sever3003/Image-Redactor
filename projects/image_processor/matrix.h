#pragma once

#include <vector>
#include "pixel.h"
#include "image.h"
#include "filter.h"


class Matrix : virtual public Filter {
public:
    using MatrixBody = std::vector<std::vector<double>>;

    Matrix(const Matrix &other) = default;

    Matrix() = default;

    Matrix(const MatrixBody &matrix_body);

    Matrix(const std::initializer_list<std::initializer_list<double>> &other);

    Image Apply(const Image &image) const override;

    Matrix &operator=(const MatrixBody &body);

    Matrix &operator=(MatrixBody &&body);


private:
    MatrixBody body_;

};
