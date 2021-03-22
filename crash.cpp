#include "crash.hpp"
#include <cstdlib>
#include <iostream>

void crash(std::string msg)
{
    std::cerr << msg << std::endl;
    std::exit(1);
}