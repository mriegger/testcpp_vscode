#pragma once

#include <chrono>

namespace Timer {
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

inline TimePoint now() { return std::chrono::system_clock::now(); }

inline double elapsedSeconds(const TimePoint &start) {
  std::chrono::duration<double, std::milli> ms =
      std::chrono::system_clock::now() - start;
  return ms.count() * 0.001;
}

inline double getElapsedMilliseconds(const TimePoint &start) {
  std::chrono::duration<double, std::milli> ms =
      std::chrono::system_clock::now() - start;
  return ms.count();
}

}; // namespace Timer