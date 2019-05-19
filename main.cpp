#include <iostream>
#include "func.h"
#include "helix.h"

using namespace std;

void guiWaitEnter(long* value)
{
    while (true)
    {
        std::cin >> *value;
        break;
    }
}

int main()
{
    clearScreen();
    long size = 0;
    std::cout << "Enter a non-negative and non-even number (0 - exit): ";
    guiWaitEnter(&size);

    if(size == 0) return 0;
    if (size < 0 || size % 2 == 0)
    {
        std::cout << "Error, try more: ";
        guiWaitEnter(&size);
    }

    Helix* helix = new Helix(size);

    clearScreen();
    cout << endl << "Field size: " << size << " x " << size << endl << endl;

    long ansver = 0;

    std::cout << "Phase #1 (BL)." << endl;
    helix->drawHBL();
    helix->printField();

    std::cout << "Phase #2 (LT). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHLT();
    helix->printField();

    std::cout << "Phase #3 (TR). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHTR();
    helix->printField();

    std::cout << "Phase #4 (RB). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHRB();
    helix->printField();

    std::cout << "Phase #5 (BR). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHBR();
    helix->printField();

    std::cout << "Phase #6 (RT). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHRT();
    helix->printField();

    std::cout << "Phase #7 (TL). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHTL();
    helix->printField();

    std::cout << "Phase #8 (LB). 1 - next, else - exit: ";
    guiWaitEnter(&ansver);
    if (ansver != 1) return 0;
    helix->drawHLB();
    helix->printField();

    cout << "FINISH, enter anything" << endl;
    guiWaitEnter(&ansver);

    delete helix;
    return 0;
}
