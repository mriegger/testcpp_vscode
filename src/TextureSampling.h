#pragma once

#include "hlsl.h"
#include <vector>

namespace TextureSampling {
struct Image {
  std::vector<std::vector<float>> data;
  float2 dim;
};

float bilinearSample(const Image &image, const float2 &uv);

void fill(Image &image);
void fillRow(std::vector<float> &row, const float startValue);
} // namespace TextureSampling