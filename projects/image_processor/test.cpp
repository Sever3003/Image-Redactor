#include "test.h"
#include "BMP.h"

#include <iostream>
#include <fstream>
//#include <catch.hpp>
const std::string INPUT_FILE = "/Users/severina/Documents/cpp-base-hse-2022-main-projects-image_processor/projects/image_processor/examples/example.bmp";
const std::string TEST_OUTPUT_FILE = "/Users/severina/Documents/cpp-base-hse-2022-main-projects-image_processor/projects/image_processor/examples/test.bmp";
const std::string PATH_INVALID_FILE = "/Users/severina/Documents/cpp-base-hse-2022-main-projects-image_processor/projects/image_processor/examples/test.bmp";

void CompareFile(const std::string& first, const std::string& second) {
    std::ifstream fin_first;
    fin_first.open(first, std::ios::binary);
    std::ifstream fin_second;
    fin_second.open(second, std::ios::binary);
    assert(fin_first && fin_second);
    while (!fin_first.eof() && !fin_second.eof()) {
        char first_byte;
        char second_byte;
        fin_first.read(&first_byte, sizeof(char));
        fin_second.read(&second_byte, sizeof(char));
        assert(first_byte == second_byte);
    }
    assert(fin_first.eof() && fin_second.eof());
    fin_first.close();
    fin_second.close();
}


void TestInvalidPath() {
    BMP bmp;
    bmp.Read("...");
    assert(!bmp.IsCorrect());
}

void TestReadWrite() {
    BMP bmp;
    bmp.Read(INPUT_FILE);
    bmp.Write(TEST_OUTPUT_FILE);
    CompareFile(INPUT_FILE, TEST_OUTPUT_FILE);
}


void TestInvalidFile() {
    char c = '1';
    std::ofstream fout;
    fout.open(PATH_INVALID_FILE, std::ios::binary);
    for (int i = 0; i < 22; ++i) {
        fout << c;
    }
    fout.close();
    BMP bmp;
    bmp.Read(PATH_INVALID_FILE);
    assert(!bmp.IsCorrect());
}

void TestSuite() {
    TestInvalidPath();
    TestReadWrite();
    TestInvalidFile();
}

