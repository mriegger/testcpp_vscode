#pragma once

#include "hlsl.h"
#include <span>
#include <string_view>
#include <vector>

// PPM is the simplest image format. A simple header followed by raw RGB data
namespace ppm {
struct Image {
  std::vector<uint8_t> imageData;
  size_t width = 0;
  size_t height = 0;
};

void write(const Image &imageData, const std::string_view filename);
Image rotate(const Image &image, const float degrees);
Image load(const std::string_view filename, const int width,
           const std::span<uint8_t> rgbData);

float3 getPixel(const Image &image, const int x, const int y);
} // namespace ppm