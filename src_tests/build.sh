clear
clang++ main.cpp -std=c++17 -L/opt/homebrew/Cellar/googletest/1.12.1_1/lib -I/opt/homebrew/Cellar/googletest/1.12.1_1/include -lgtest
./a.out --gtest_repeat=1 --gtest_shuffle