#include "helix.h"
#include "func.h"

#include <iostream>

using namespace std;

Helix::Helix(long size)
{
    m_size = size;
    auto s = static_cast<unsigned long>(size);

    m_helixITL = new long *[s];
    for (long i = 0; i < size; i++) m_helixITL[i] = new long [s];
    m_helixIRT = new long *[s];
    for (long i = 0; i < size; i++) m_helixIRT[i] = new long [s];
    m_helixIBR = new long *[s];
    for (long i = 0; i < size; i++) m_helixIBR[i] = new long [s];
    m_helixILB = new long *[s];
    for (long i = 0; i < size; i++) m_helixILB[i] = new long [s];
    m_helixITR = new long *[s];
    for (long i = 0; i < size; i++) m_helixITR[i] = new long [s];
    m_helixIRB = new long *[s];
    for (long i = 0; i < size; i++) m_helixIRB[i] = new long [s];
    m_helixIBL = new long *[s];
    for (long i = 0; i < size; i++) m_helixIBL[i] = new long [s];
    m_helixILT = new long *[s];
    for (long i = 0; i < size; i++) m_helixILT[i] = new long [s];

    m_field = new char *[s];
    for (long i = 0; i < size; i++) m_field[i] = new char [s];
    clearField();

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
    for (long i = 0; i < m_size; i++) delete[]m_helixITL[i];
    delete[]m_helixITL;
    for (long i = 0; i < m_size; i++) delete[]m_helixIRT[i];
    delete[]m_helixIRT;
    for (long i = 0; i < m_size; i++) delete[]m_helixIBR[i];
    delete[]m_helixIBR;
    for (long i = 0; i < m_size; i++) delete[]m_helixILB[i];
    delete[]m_helixILB;
    for (long i = 0; i < m_size; i++) delete[]m_helixITR[i];
    delete[]m_helixITR;
    for (long i = 0; i < m_size; i++) delete[]m_helixIRB[i];
    delete[]m_helixIRB;
    for (long i = 0; i < m_size; i++) delete[]m_helixIBL[i];
    delete[]m_helixIBL;
    for (long i = 0; i < m_size; i++) delete[]m_helixILT[i];
    delete[]m_helixILT;
    for (long i = 0; i < m_size; i++) delete[]m_field[i];
    delete[]m_field;
}

void Helix::printField()
{
    clearScreen();
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            cout << m_field[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}

void Helix::clearField()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            m_field[i][j] = '-';
        }
    }
}

void Helix::fillField(long **m)
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            if (isPrimitive(m[i][j]))
                m_field[i][j] = '#';
        }
    }
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
