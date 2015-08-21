add_library(logger STATIC logger.cpp)
target_compile_features(logger PRIVATE cxx_range_for)
