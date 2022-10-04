#include <atomic>
#include <thread>

class Spinlock final {
  std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
  void lock() {
    while (flag.test_and_set())
      ;
  }

  void unlock() { flag.clear(); }
};
