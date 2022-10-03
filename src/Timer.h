#pragma once

#include <chrono>

class Timer final {
public:
  Timer() { start(); }

  void start() { startTime_ = std::chrono::system_clock::now(); }

  double getElapsedSeconds() const {
    std::chrono::duration<double, std::milli> ms =
        std::chrono::system_clock::now() - startTime_;
    return ms.count() * 0.001;
  }
  double getElapsedMilliseconds() const {
    std::chrono::duration<double, std::milli> ms =
        std::chrono::system_clock::now() - startTime_;
    return ms.count();
  }

private:
  std::chrono::time_point<std::chrono::system_clock> startTime_;
};