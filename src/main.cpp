#include "PPMCreator.h"
#include "Timer.h"
#include "hlsl.h"
#include "Colors.h"
#include "RandomNumberGenerator.h"
#include "ProducerConsumer.h"
#include "TextureSampling.h"
#include "Sorting.h"
#include <cstdio>
#include <format>
#include <iostream>
#include <benchmark/benchmark.h>
#include "ExampleGoogleBenchmark.h"

void doExpensiveFunction(const int i) {
  PPMCreator p;
  std::vector<uint8_t> v(128 * 128 * 3, 255);

  p.SetImageData(std::span<uint8_t>(v), 128);
  p.Rotate(45);

  // const std::string filename = "../deleteme/hello" + std::to_string(i) +
  // ".ppm";
  // p.Write(filename);
}

#define MKR_PUTS puts("MKR hello!")

const int& getI(){
  static int x = 5;
  return x;
}

int main() {

using namespace std;

Timer t;

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
  t.start();
  for(int i =  0; i < numloops ; ++i){
    std::memcpy(dst.v.data(), src.v.data(), dataSize);
  //  dst = src;
  }
  (void)src;
  (void)dst;
  auto ms = t.getElapsedMilliseconds();
  auto avgPerIteration = ms / double(numloops);
  auto tmp = std::accumulate(dst.v.begin(), dst.v.end(), 0);

  std::cout << "avg ms per copy " << avgPerIteration << std::endl;;
  std::cout << tmp << std::endl;



  return 0;
}

//BENCHMARK_MAIN(); 
