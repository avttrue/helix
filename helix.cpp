#include "helix.h"
#include "func.h"

#include <iostream>

using namespace std;

Helix::Helix(long size)
{
    m_size = size;
    auto s = static_cast<unsigned long>(size);

    m_helixTL = new long *[s];
    for (long i = 0; i < size; i++) m_helixTL[i] = new long [s];
    m_helixRT = new long *[s];
    for (long i = 0; i < size; i++) m_helixRT[i] = new long [s];
    m_helixBR = new long *[s];
    for (long i = 0; i < size; i++) m_helixBR[i] = new long [s];
    m_helixLB = new long *[s];
    for (long i = 0; i < size; i++) m_helixLB[i] = new long [s];
    m_helixTR = new long *[s];
    for (long i = 0; i < size; i++) m_helixTR[i] = new long [s];
    m_helixRB = new long *[s];
    for (long i = 0; i < size; i++) m_helixRB[i] = new long [s];
    m_helixBL = new long *[s];
    for (long i = 0; i < size; i++) m_helixBL[i] = new long [s];
    m_helixLT = new long *[s];
    for (long i = 0; i < size; i++) m_helixLT[i] = new long [s];

    m_field = new char *[s];
    for (long i = 0; i < size; i++) m_field[i] = new char [s];
    clearField();

    fillHTL();
    fillHRT();
    fillHBR();
    fillHLB();
    fillHTR();
    fillHRB();
    fillHBL();
    fillHLT();
}

Helix::~Helix()
{
    for (long i = 0; i < m_size; i++) delete[]m_helixTL[i];
    delete[]m_helixTL;
    for (long i = 0; i < m_size; i++) delete[]m_helixRT[i];
    delete[]m_helixRT;
    for (long i = 0; i < m_size; i++) delete[]m_helixBR[i];
    delete[]m_helixBR;
    for (long i = 0; i < m_size; i++) delete[]m_helixLB[i];
    delete[]m_helixLB;
    for (long i = 0; i < m_size; i++) delete[]m_helixTR[i];
    delete[]m_helixTR;
    for (long i = 0; i < m_size; i++) delete[]m_helixRB[i];
    delete[]m_helixRB;
    for (long i = 0; i < m_size; i++) delete[]m_helixBL[i];
    delete[]m_helixBL;
    for (long i = 0; i < m_size; i++) delete[]m_helixLT[i];
    delete[]m_helixLT;
    for (long i = 0; i < m_size; i++) delete[]m_field[i];
    delete[]m_field;
}

void Helix::printField()
{
    clearScreen();
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++) cout << m_field[i][j];
        cout << endl;
    }
    cout  << endl;
}

void Helix::clearField()
{
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++) m_field[i][j] = '-';
}

void Helix::fillField(long **m)
{
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            if (isPrimitive(m[i][j])) m_field[i][j] = '#';
}

void Helix::fillHTL()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "TL: ";
    while(value)
    {
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixTL[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixTL[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixTL[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixTL[rowBeg][i] = value--;
        rowBeg++; cout << '-';
    }
    cout << endl;
}

void Helix::fillHRT()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "RT: ";
    while(value)
    {
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixRT[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixRT[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixRT[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixRT[i][colEnd] = value--;
        colEnd--; cout << '|';
    }
    cout << endl;
}

void Helix::fillHBR()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "BR: ";
    while(value)
    {
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixBR[i][colBeg] = value--;
        colBeg++; cout << '|';
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixBR[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixBR[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixBR[rowEnd][i] = value--;
        rowEnd--; cout << '-';
    }
    cout << endl;
}

void Helix::fillHLB()
{
    long rowBeg = 0, colBeg = 0;
    long rowEnd = m_size - 1, colEnd = m_size - 1;
    long value = m_size * m_size;
    cout << "LB: ";
    while(value)
    {
        for(long i = colBeg; i <= colEnd && value; i++)
            m_helixLB[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixLB[i][colEnd] = value--;
        colEnd--; cout << '|';
        for(long i = colEnd; i >= colBeg && value; i--)
            m_helixLB[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixLB[i][colBeg] = value--;
        colBeg++; cout << '|';
    }
    cout << endl;
}

void Helix::fillHRB()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "RB: ";
    while(value)
    {
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixRB[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixRB[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixRB[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixRB[i][colBeg] = value--;
        colBeg--; cout << '|';
    }
    cout << endl;
}

void Helix::fillHBL()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "BL: ";
    while(value)
    {
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixBL[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixBL[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixBL[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixBL[rowEnd][i] = value--;
        rowEnd--; cout << '-';
    }
    cout << endl;
}

void Helix::fillHLT()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "LT: ";
    while(value)
    {
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixLT[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixLT[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixLT[rowBeg][i] = value--;
        rowBeg++; cout << '-';
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixLT[i][colEnd] = value--;
        colEnd++; cout << '|';
    }
    cout << endl;
}

void Helix::fillHTR()
{
    long rowBeg = 0, colEnd = 0;
    long rowEnd = m_size - 1, colBeg = m_size - 1;
    long value = m_size * m_size;
    cout << "TR: ";
    while(value)
    {
        for(long i = rowBeg; i <= rowEnd && value; i++)
            m_helixTR[i][colEnd] = value--;
        colEnd++; cout << '|';
        for(long i = colEnd; i <= colBeg && value; i++)
            m_helixTR[rowEnd][i] = value--;
        rowEnd--; cout << '-';
        for(long i = rowEnd; i >= rowBeg && value; i--)
            m_helixTR[i][colBeg] = value--;
        colBeg--; cout << '|';
        for(long i = colBeg; i >= colEnd && value; i--)
            m_helixTR[rowBeg][i] = value--;
        rowBeg++; cout << '-';
    }
    cout << endl;
}
