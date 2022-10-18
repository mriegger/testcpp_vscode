#pragma once

#include <cassert>
#include <compare> // needed for the spaceship operator
#include <set>

// https://www.youtube.com/watch?v=0SeUPb8LC9I
class SpaceshipOperator final {
public:
  static void Test() {
    struct Data {
      int i;
      int j;

      // Gives us ALL the operators!
      auto operator<=>(const Data &rhs) const = default;
    };

    std::set<Data> s;
    s.emplace(Data{5, 6}); // comparisons used by set automatically generated!

    Data a{1, 2};
    Data c = a;
    Data b{2, 1};
    assert(a != b); // automatically generated!
    assert(a == c); // automatically generated!

    assert(a < b);
  }

private:
};