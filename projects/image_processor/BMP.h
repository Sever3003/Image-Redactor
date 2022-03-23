#pragma once

#include "pixel.h"
#include "filter.h"
#include "matrix.h"
#include <iostream>
#include <array>

class Filter;

static const size_t HEADER_SIZE = 54;
static const size_t WIDTH_BYTE = 18;
static const size_t HEIGHT_BYTE = 22;
static const size_t FILE_SIZE_BYTE = 2;

class BMP {

public:
    void Read(const std::string &input_file_name);

    void Apply(const Filter &filter);

    bool IsCorrect() const;

    void Write(const std::string &output_file_name) const;


private:
    std::array<uint8_t, HEADER_SIZE> header_;
    Image image_;
    bool correct_;

};

