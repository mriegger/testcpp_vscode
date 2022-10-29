#pragma once

#include <random>

// Example use:

// rng::engine e;
// float f = randomFloat(e, 1.0f, 2.0f); 

namespace rng {
using engine = std::default_random_engine;

float randomFloat(engine &e, const float minVal, const float maxVal) {
  std::uniform_real_distribution<float> uniform_distance(minVal, maxVal);
  return uniform_distance(e);
}

double randomDouble(engine &e, const double minVal, const double maxVal) {
  std::uniform_real_distribution<double> uniform_distance(minVal, maxVal);
  return uniform_distance(e);
}

int randomInt(engine &e, const int minVal, const int maxVal) {
  std::uniform_int_distribution<int> uniform_distance(minVal, maxVal);
  return uniform_distance(e);
}
} // namespace rng