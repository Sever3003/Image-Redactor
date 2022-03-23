#include "BMP.h"
#include <iostream>
#include <fstream>

void BMP::Apply(const Filter &filter) {
    image_ = filter.Apply(image_);
    *(reinterpret_cast<int *>(header_.data() + HEIGHT_BYTE)) = image_.Height();
    *(reinterpret_cast<int *>(header_.data() + WIDTH_BYTE)) = image_.Width();
    *(reinterpret_cast<int *>(header_.data() + FILE_SIZE_BYTE)) =
            image_.Height() * image_.Width() * sizeof(Pixel) + HEADER_SIZE;
}


void BMP::Read(const std::string &input_file_name) {
    correct_ = true;
    std::ifstream fin;
    fin.open(input_file_name, std::ios::binary);
    if (fin) {
        fin.read(reinterpret_cast<char *>(header_.data()), sizeof(uint8_t) * HEADER_SIZE);
        if (fin.gcount() != HEADER_SIZE) {
            correct_ = false;
            return;
        }
        int width = *(reinterpret_cast<int *>(header_.data() + WIDTH_BYTE));
        int height = *(reinterpret_cast<int *>(header_.data() + HEIGHT_BYTE));
        if (width <= 0 || height <= 0) {
            correct_ = false;
            return;
        }
        Image body(height, width);
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                Pixel pixel{};
                if (fin.eof()) {
                    correct_ = false;
                    fin.close();
                    return;
                }
                uint8_t color;
                fin.read(reinterpret_cast<char *>(&color), sizeof(uint8_t));
                pixel.blue = color;
                fin.read(reinterpret_cast<char *>(&color), sizeof(uint8_t));
                pixel.green = color;
                fin.read(reinterpret_cast<char *>(&color), sizeof(uint8_t));
                pixel.red = color;
                body.At(height - 1 - i, j) = pixel;
            }
        }
        image_ = body;
        fin.close();
    } else {
        correct_ = false;
    }
}


bool BMP::IsCorrect() const {
    return correct_;
};


void BMP::Write(const std::string &output_file_name) const {
    if (!correct_) {
        return;
    }
    std::ofstream fout;
    fout.open(output_file_name, std::ios::binary);
    if (fout) {
        fout.write(reinterpret_cast<const char *>(header_.data()), sizeof(uint8_t) * HEADER_SIZE);
        for (size_t i = 0; i < image_.Height(); ++i) {
            for (size_t j = 0; j < image_.Width(); ++j) {
                fout.write(reinterpret_cast<const char *>(&image_.At(image_.Height() - 1 - i, j)), sizeof(Pixel));
            }
        }
        fout.close();
    } else {
        std::cout << "File did not open" << std::endl;
    }
}
