cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#add_library(contrib_catch_main
#        ../../contrib/catch/catch_main.cpp)
#
#target_include_directories(contrib_catch_main
#        PUBLIC ../../contrib/catch)

add_executable(image_processor
        matrix.cpp
        BMP.cpp
        image_processor.cpp
        negative_filter.cpp
        grayscale_filter.cpp
        crop_filter.cpp
        sharpening_filter.cpp
        edge_detection_filter.cpp
        gaussian_blur_filter.cpp
        hexagonal_pixel.cpp
        image.cpp
        test.cpp)
#add_subdirectory(test)
