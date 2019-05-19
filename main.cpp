#include <iostream>
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
    //long size = 0;

    //    while (true)
    //    {
    //        std::cout << "Enter a non-negative number (0 - exit): ";
    //        std::cin >> size;
    //        if (size <= 0) return 0;
    //        else break;
    //    }
    long size = 0;
    std::cout << "Enter a non-negative number (0 - exit): ";
    guiWait(&size);
    if (size <= 0) return 0;

    Helix* helix = new Helix(size);

    std::system("clear");
    cout << endl << "matrix: " << size << " x " << size << endl << endl;

    long ansver = 0;
    helix->drawHIBL();
    helix->printField();

    std::cout << "Fase #2. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHIBR();
    helix->printField();

    std::cout << "Fase #3. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHILB();
    helix->printField();

    std::cout << "Fase #4. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHILT();
    helix->printField();

    std::cout << "Fase #5. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHIRB();
    helix->printField();

    std::cout << "Fase #6. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHIRT();
    helix->printField();

    std::cout << "Fase #7. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHITL();
    helix->printField();

    std::cout << "Fase #8. 1 - next (0 - exit): ";
    guiWait(&ansver);
    if (ansver == 0) return 0;
    helix->drawHITR();
    helix->printField();


    cout << "THE END" << endl;

    delete helix;
    return 0;
}
