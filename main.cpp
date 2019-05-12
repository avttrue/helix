#include <iostream>
#include "helix.h"

using namespace std;

int main()
{
    long size = 0;

    while (true)
    {
        std::cout << "Enter a non-negative number (0 - exit): ";

        std::cin >> size;

        if (size <= 0) return 0;
        else break;

    }

    Helix* helix = new Helix(size);

    std::system("clear");
    cout << endl << "matrix: " << size << " x " << size << endl << endl;

    helix->printHIBL();

    cout << endl << endl;

    delete helix;
    return 0;
}
