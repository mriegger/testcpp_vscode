#include <cstdio>
#include <cstdlib>
#include <iostream>

void * operator new(size_t size)
{
    //std::cout << "1\n";
    return malloc(size);
}

void operator delete(void *ptr) noexcept
{
    //std::cout << "2\n";
    free(ptr);
}