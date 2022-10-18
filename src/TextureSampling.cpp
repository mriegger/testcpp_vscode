#include "TextureSampling.h"

namespace TextureSampling {
float bilinearSample(const Image &image, const float2 &uv) {
  // From Anki question How is bilinear and trilinear filtering performed?
  float u = uv.x * image.dim.x - 0.5f;
  float v = uv.y * image.dim.y - 0.5f;
  int x = (int)floor(u);
  int y = (int)floor(v);
  float u_ratio = u - x;
  float v_ratio = v - y;
  float u_opposite = 1 - u_ratio;
  float v_opposite = 1 - v_ratio;

  float result =
      (image.data[x][y] * u_opposite + image.data[x + 1][y] * u_ratio) *
          v_opposite +
      (image.data[x][y + 1] * u_opposite + image.data[x + 1][y + 1] * u_ratio) *
          v_ratio;

  return result;
}

void fill(Image &image) {
  float startValue = 1;
  image.data.resize((size_t)image.dim.y);
  for (auto &row : image.data) {
    row.resize((size_t)image.dim.x);
    fillRow(image, row, startValue);
    startValue += image.dim.x;
  }
}

void fillRow(Image &image, std::vector<float> &row, const float startValue) {
  float currValue = startValue;
  for (size_t i = 0; i < row.size(); ++i) {
    row[i] = currValue;
    currValue += 1.0f;
  }
}

} // namespace TextureSampling