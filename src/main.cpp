#include "printf_howto.h"
#include "BinarySearch.h"
#include "Colors.h"
#include "ExampleGoogleBenchmark.h"
#include "PPMCreator.h"
#include "ProducerConsumer.h"
#include "RandomNumberGenerator.h"
#include "Sorting.h"
#include "TextureSampling.h"
#include "Timer.h"
#include "hlsl.h"
#include <any>
#include <benchmark/benchmark.h>
#include <cassert>
#include <cstdio>
#include <format>
#include <functional>
#include <future>
#include <list>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

#include <iostream>
using namespace std;
void doExpensiveFunction(const int i) {

  const std::string filename = "../deleteme/hello" + std::to_string(i) + ".ppm";

  ppm::Image image;
  image.height = image.width = 128;
  image.imageData.resize(128 * 128 * 3, 128);

  image = ppm::rotate(image, 45.0f);
  // ppm::write(image, filename);
}

void doSomething2() { throw std::invalid_argument("fmnwkjmk"); }

void doSomething() {
  try {
    doSomething2();
  } catch (const std::invalid_argument &e) {
    puts("caught exception");
    cout << e.what() << endl;
    throw;
  }
}


int main(int , char *[]) {

  printf_howto::displayExamples();

  return 0;
}
