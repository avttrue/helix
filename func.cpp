#include "func.h"

#include <iostream>
#include <math.h>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#endif

#ifdef __linux__
    std::system("clear");
#endif
}



bool isPrimitive(long n)
{
    for (long i = 2; i<sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

#include "func.h"
