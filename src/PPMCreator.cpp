#include "PPMCreator.h"
#include <fstream>
#include <iostream>
#include <string>

namespace {
static constexpr std::string_view MagicNumber = "P6\n";
static constexpr std::string_view MaxValue = "255\n";
static constexpr size_t NumColorChannels = 3;

void WritePPMHeader(std::ofstream &f, const size_t width, const size_t height) {
  f.write(MagicNumber.data(), MagicNumber.size());
  const std::string widthHeightStr =
      std::to_string(width) + " " + std::to_string(height) + "\n";
  f.write(widthHeightStr.data(), (std::streamsize)widthHeightStr.size());
  f.write(MaxValue.data(), MaxValue.size());
}
} // namespace

namespace ppm {

void write(const Image &image, const std::string_view filename) {
  using namespace std;
  ofstream f;
  f.open(filename.data(), ios::out | ios::binary);
  WritePPMHeader(f, image.width, image.height);
  f.write(reinterpret_cast<const char *>(image.imageData.data()),
          (std::streamsize)image.imageData.size());
  f.close();
}

float3 getPixel(const Image &image, const size_t x, const size_t y) {
  if (x < 0 || y < 0 || x >= image.width || y >= image.height) {
    std::cerr << "PPMCreator::getPixel() called with out of bounds data"
              << std::endl;
    return float3(0, 0, 0);
  }
  const auto index = (x + y * image.width) * NumColorChannels;
  const float red = image.imageData[index + 0];
  const float green = image.imageData[index + 1];
  const float blue = image.imageData[index + 2];
  return float3(red, green, blue) / 255.0f;
}

Image rotate(const Image &image, const float degrees) {
  const float2 translateXY(image.width / 2.0f, image.height / 2.0f);

  Image result;
  result.imageData.resize(image.imageData.size(), 0);
  result.width = image.width;
  result.height = image.height;

  const float rad = radians(degrees);
  const float3x3 invTranslate = {
      1.0, 0.0f, -translateXY.x, 0.0f, 1.0f, -translateXY.y, 0, 0, 1};

  const float3x3 rotate = {cosf(rad), -sinf(rad), 0.0f, sinf(rad), cosf(rad),
                           0.0f,      0,          0,    1};

  const float3x3 translate = {
      1.0, 0.0f, translateXY.x, 0.0f, 1.0f, translateXY.y, 0, 0, 1};

  float3x3 final = mul(rotate, invTranslate);
  final = mul(translate, final);
  for (size_t y = 0; y < image.height; ++y) {
    for (size_t x = 0; x < image.width; ++x) {
      const float3 color = getPixel(image, x, y);
      const float3 srcVertex(x, y, 1);
      const float3 destVertex = mul(final, srcVertex);

      if (destVertex.x >= 0 && destVertex.y >= 0 &&
          destVertex.x < image.width && destVertex.y < image.height) {

        const auto index = (x + y * image.width) * NumColorChannels;
        result.imageData[index + 0] = (uint8_t)(color.x * 255);
        result.imageData[index + 1] = (uint8_t)(color.y * 255);
        result.imageData[index + 2] = (uint8_t)(color.z * 255);
      }
    }
  }
  return result;
}

Image load(const std::string_view filename, const size_t width) {

  Image image;

  using namespace std;
  ofstream f;
  f.open(filename.data(), ios::out | ios::binary);
  const auto numPixels = image.imageData.size();
  const auto height = numPixels / NumColorChannels / width;

  WritePPMHeader(f, width, height);

  f.write(reinterpret_cast<const char *>(image.imageData.data()),
          (std::streamsize)image.imageData.size());
  f.close();
  return image;
}

} // namespace ppm
