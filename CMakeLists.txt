project(clogger)
cmake_minimum_required(VERSION 3.2)
add_library(logger STATIC fileprovider.cpp logger.cpp )
target_compile_features(logger PRIVATE cxx_range_for)

