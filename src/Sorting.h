#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

class Sorting {
public:
  static void MergeSort(std::vector<int> &v) {
    MergeSort(v, 0, (int)v.size() - 1);
  }

  static void Test() {
    std::vector<int> v = {5, 4, 6, 3, 1, 3, 5, 7, 9, -1, 1, 0, -9};
    MergeSort(v);
    assert(std::is_sorted(v.begin(), v.end()));
  }

private:
  static void MergeSort(std::vector<int> &v, int left, int right) {
    int len = right - left + 1;
    if (len <= 1)
      return;

    int middle = left + (right - left) / 2;
    MergeSort(v, left, middle);
    MergeSort(v, middle + 1, right);
    const auto merged = Merge(v, (size_t)left, (size_t)middle, (size_t)middle + 1, (size_t)right);
    std::copy(merged.begin(), merged.end(), v.begin() + left);
  }

  static std::vector<int> Merge(std::vector<int> &v, size_t a, size_t b, size_t c,
                                size_t d) {
    std::vector<int> result;
    while (a <= b && c <= d) {
      if (v[a] <= v[c]) {
        result.push_back(v[a++]);
      } else {
        result.push_back(v[c++]);
      }
    }
    while (a <= b)
      result.push_back(v[a++]);
    while (c <= d)
      result.push_back(v[c++]);
    return result;
  }
};