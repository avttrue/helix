#ifndef HELIX_H
#define HELIX_H

#include <vector>

class Helix
{
public:
    Helix(long size);
    ~Helix();

    long size() { return m_size; }
    void printHITL() { printMatrix(m_helixITL); }
    void printHIRT() { printMatrix(m_helixIRT); }
    void printHIBR() { printMatrix(m_helixIBR); }
    void printHILB() { printMatrix(m_helixILB); }
    void printHITR() { printMatrix(m_helixITR); }
    void printHIRB() { printMatrix(m_helixIRB); }
    void printHIBL() { printMatrix(m_helixIBL); }
    void printHILT() { printMatrix(m_helixILT); }

    long valueHITL(long row, long col) { return m_helixITL[row][col]; }
    long valueHIRT(long row, long col) { return m_helixIRT[row][col]; }
    long valueHIBR(long row, long col) { return m_helixIBR[row][col]; }
    long valueHILB(long row, long col) { return m_helixILB[row][col]; }

private:
    long m_size = 0;
    long ** m_helixITL = nullptr;
    long ** m_helixIRT = nullptr;
    long ** m_helixIBR = nullptr;
    long ** m_helixILB = nullptr;
    long ** m_helixITR = nullptr;
    long ** m_helixIRB = nullptr;
    long ** m_helixIBL = nullptr;
    long ** m_helixILT = nullptr;

    void printMatrix(long **m);
    void fillHITL();
    void fillHIRT();
    void fillHIBR();
    void fillHILB();
    void fillHITR();
    void fillHIRB();
    void fillHIBL();
    void fillHILT();
};

#endif // HELIX_H
