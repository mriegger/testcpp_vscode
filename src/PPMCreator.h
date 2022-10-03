#pragma once

#include "hlsl.h"
#include <span>
#include <string_view>
#include <vector>

// PPM is the simplest image format. A simple header followed by raw RGB data
class PPMCreator final {
public:
  // Write an image with a single function
  static void Create(const std::string_view filename, const int width,
                     const std::span<uint8_t> rgbData);

  void SetImageData(const std::span<uint8_t> rgbData, const int width);
  void SetPixel(const int x, const int y, const uint8_t red,
                const uint8_t green, const uint8_t blue);
  void SetPixel(const int x, const int y, const float3 color);
  float3 GetPixel(const int x, const int y) const;
  void Write(const std::string_view filename);
  // From Microsoft XBOX graphics interview
  void Rotate(const float degrees);
  std::vector<uint8_t> GetImageData() const;

private:
  std::vector<uint8_t> m_imageData;
  size_t m_width = 128;
  size_t m_height = 128;
};