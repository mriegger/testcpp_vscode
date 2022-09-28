#include <cstdio>
#include <iostream>
#include "Timer.h"
#include "hlsl.h"
#include "PPMCreator.h"

void doExpensiveFunction(const int i)
{
    PPMCreator p;
    std::vector<uint8_t> v(128*128*3, 255);    

    p.SetImageData(std::span<uint8_t>(v), 128);
    p.Rotate(45);

    //const std::string filename = "../deleteme/hello" + std::to_string(i) + ".ppm"; 
   // p.Write(filename);
}

int main(){

    Timer t;
    t.start();

    int counter = 0;
    while(t.getElapsedMilliseconds() < 5000)
    {
        doExpensiveFunction(++counter);
    }

    std::vector<int> v(2048,0);
    for(int i = 0 ; i < 2048 ; ++i)
    {
        v[i] = i;
    }

    std::cout << "I did " << counter << " iterations" << std::endl;

 
    return 0;
}
