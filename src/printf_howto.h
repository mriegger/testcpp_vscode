#include <cstdio>
#include <limits>

namespace printf_howto {
inline void displayExamples() {
  int i = std::numeric_limits<int>::min();
  unsigned int ui = std::numeric_limits<unsigned int>::max();
  size_t st = std::numeric_limits<size_t>::max();
  unsigned long long ull = std::numeric_limits<unsigned long long>::max();
  long long ll = std::numeric_limits<long long>::min();
  ptrdiff_t p = std::numeric_limits<ptrdiff_t>::min();
  long l = std::numeric_limits<long>::min();
  char c = std::numeric_limits<char>::min();
  unsigned char uc = std::numeric_limits<unsigned char>::max();
  double d = std::numeric_limits<double>::min();

  short s = std::numeric_limits<short>::min();
  unsigned short us = std::numeric_limits<unsigned short>::max();

  long double ld = std::numeric_limits<long double>::min();
  float f = std::numeric_limits<float>::min();

  // 8-bit
  printf("%d\n", c);
  printf("%u\n", uc);

  // 16-bit
  printf("%d\n", s);
  printf("%u\n", us);

  // 32-bit
  printf("%d\n", i);
  printf("%u\n", ui);

  // 64-bit
  printf("%ld\n", l);
  printf("%lld\n", ll);
  printf("%llu\n", ull);
  printf("%zu\n", st); // size_t
  printf("%td\n", p);  // ptrdiff_t

  // floating-point
  printf("%g\n", f);   // %g chooses either %f or %e depending upon magnitude
  printf("%g\n", d);   // %g chooses either %f or %e depending upon magnitude
  printf("%Lg\n", ld); // %g chooses either %f or %e depending upon magnitude

  printf("%o\n", ui); // octal
  printf("%x\n", ui); // hex
}
} // namespace printf_howto