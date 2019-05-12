#include "helix.h"
#include "helix.h"
#include <iostream>

using namespace std;

Helix::Helix(long size)
{
    m_size = size;

    m_helixITL = new long *[size];
    for (long i = 0; i < size; i++) m_helixITL[i] = new long [size];
    m_helixIRT = new long *[size];
    for (long i = 0; i < size; i++) m_helixIRT[i] = new long [size];
    m_helixIBR = new long *[size];
    for (long i = 0; i < size; i++) m_helixIBR[i] = new long [size];
    m_helixILB = new long *[size];
    for (long i = 0; i < size; i++) m_helixILB[i] = new long [size];
    m_helixITR = new long *[size];
    for (long i = 0; i < size; i++) m_helixITR[i] = new long [size];
    m_helixIRB = new long *[size];
    for (long i = 0; i < size; i++) m_helixIRB[i] = new long [size];
    m_helixIBL = new long *[size];
    for (long i = 0; i < size; i++) m_helixIBL[i] = new long [size];
    m_helixILT = new long *[size];
    for (long i = 0; i < size; i++) m_helixILT[i] = new long [size];

    fillHITL();
    fillHIRT();
    fillHIBR();
    fillHILB();
    fillHITR();
    fillHIRB();
    fillHIBL();
    fillHILT();
}

Helix::~Helix()
{
    for (int i = 0; i < m_size; i++) delete[]m_helixITL[i];
    delete[]m_helixITL;
    for (int i = 0; i < m_size; i++) delete[]m_helixIRT[i];
    delete[]m_helixIRT;
    for (int i = 0; i < m_size; i++) delete[]m_helixIBR[i];
    delete[]m_helixIBR;
    for (int i = 0; i < m_size; i++) delete[]m_helixILB[i];
    delete[]m_helixILB;
    for (int i = 0; i < m_size; i++) delete[]m_helixITR[i];
    delete[]m_helixITR;
    for (int i = 0; i < m_size; i++) delete[]m_helixIRB[i];
    delete[]m_helixIRB;
    for (int i = 0; i < m_size; i++) delete[]m_helixIBL[i];
    delete[]m_helixIBL;
    for (int i = 0; i < m_size; i++) delete[]m_helixILT[i];
    delete[]m_helixILT;
}

void Helix::printMatrix(long **m)
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
            cout << m[i][j] << "\t";
        cout << endl << endl;
    }
    cout << endl << endl;
}

void Helix::fillHITL()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "HITL: ";
    while(value)
    {
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixITL[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixITL[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixITL[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixITL[rowBeg][i] = value--;
        rowBeg++; cout << '-';
    }
    cout << endl;
}

void Helix::fillHIRT()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "HIRT: ";
    while(value)
    {
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixIRT[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixIRT[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixIRT[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixIRT[i][colEnd] = value--;
        colEnd--; cout << '|';
    }
    cout << endl;
}

void Helix::fillHIBR()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "HIBR: ";
    while(value)
    {
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixIBR[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixIBR[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixIBR[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixIBR[rowEnd][i] = value--;
        rowEnd--; cout << '-';
    }
    cout << endl;
}

void Helix::fillHILB()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "HILB: ";
    while(value)
    {
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixILB[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixILB[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixILB[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixILB[i][colBeg] = value--;
        colBeg++; cout << '|';
    }
    cout << endl;
}

void Helix::fillHIRB()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "HIRB: ";
    while(value)
    {
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixIRB[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixIRB[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixIRB[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixIRB[i][colBeg] = value--;
        colBeg--; cout << '|';
    }
    cout << endl;
}

void Helix::fillHIBL()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "HIBL: ";
    while(value)
    {
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixIBL[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixIBL[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixIBL[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixIBL[rowEnd][i] = value--;
        rowEnd--; cout << '-';
    }
    cout << endl;
}

void Helix::fillHILT()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "HILT: ";
    while(value)
    {
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixILT[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixILT[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixILT[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixILT[i][colEnd] = value--;
        colEnd++; cout << '|';
    }
    cout << endl;
}

void Helix::fillHITR()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "HITR: ";
    while(value)
    {
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixITR[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixITR[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixITR[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixITR[rowBeg][i] = value--;
        rowBeg++; cout << '-';
    }
    cout << endl;
}
