add_library(logger STATIC logger.cpp)
add_library(FileProvider STATIC fileprovider.cpp)
target_compile_features(logger PRIVATE cxx_range_for)
