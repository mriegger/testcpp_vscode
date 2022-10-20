#include "Colors.h"
#include "ExampleGoogleBenchmark.h"
#include "PPMCreator.h"
#include "ProducerConsumer.h"
#include "RandomNumberGenerator.h"
#include "Sorting.h"
#include "TextureSampling.h"
#include "BinarySearch.h"
#include "Timer.h"
#include "hlsl.h"
#include <benchmark/benchmark.h>
#include <cstdio>
#include <format>
#include <gtest/gtest.h>
#include <iostream>

void doExpensiveFunction(const int i) {

  const std::string filename = "../deleteme/hello" + std::to_string(i) + ".ppm";

  ppm::Image image;
  image.height = image.width = 128;
  image.imageData.resize(128 * 128 * 3, 128);

  image = ppm::rotate(image, 45.0f);
  // ppm::write(image, filename);
}

#define MKR_PUTS puts("MKR hello!")

const int &getI() {
  static int x = 5;
  return x;
}

int main(int argc, char* argv[]) {

BinarySearch::Test();
  doExpensiveFunction(100);

  /*
    struct alignas(64) Temp {
      std::vector<int> v;
    };

    static constexpr int dataSize = 100*1024576;
    static constexpr int numloops = 100;
  //  std::vector<char> src(dataSize);
   // std::vector<char> dst(dataSize);
    Temp src, dst;
    src.v.resize(dataSize/sizeof(int));
    dst.v.resize(dataSize/sizeof(int));
    const auto startTime = Timer::now();
    for(int i =  0; i < numloops ; ++i){
      std::memcpy(dst.v.data(), src.v.data(), dataSize);
    //  dst = src;
    }
    (void)src;
    (void)dst;
    auto ms = Timer::getElapsedMilliseconds(startTime);

    auto avgPerIteration = ms / double(numloops);
    auto tmp = std::accumulate(dst.v.begin(), dst.v.end(), 0);

    std::cout << "avg ms per copy " << avgPerIteration << std::endl;;
    std::cout << tmp << std::endl;

  */

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

  return 0;
}

// BENCHMARK_MAIN();
