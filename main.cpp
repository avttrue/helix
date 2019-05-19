#include <iostream>
#include "func.h"
#include "helix.h"

using namespace std;

void guiWait(long* value)
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
    guiWait(&size);

    if(size == 0) return 0;
    if (size < 0 || size % 2 == 0)
    {
        std::cout << "Error, try more: ";
        guiWait(&size);
    }

    Helix* helix = new Helix(size);

    clearScreen();
    cout << endl << "Matrix: " << size << " x " << size << endl << endl;

    long ansver = 0;

    helix->drawHIBL();
    helix->printField();

    std::cout << "Phase #2. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHILT();
    helix->printField();

    std::cout << "Phase #3. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHITR();
    helix->printField();

    std::cout << "Phase #4. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHIRB();
    helix->printField();

    std::cout << "Phase #5. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHIBR();
    helix->printField();

    std::cout << "Phase #6. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHIRT();
    helix->printField();

    std::cout << "Phase #7. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHITL();
    helix->printField();

    std::cout << "Phase #8. 1 - next, else - exit: ";
    guiWait(&ansver);
    if (ansver != 1) return 0;
    helix->drawHILB();
    helix->printField();

    cout << "FINISH, enter anything" << endl;
    guiWait(&ansver);

    delete helix;
    return 0;
}
