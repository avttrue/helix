#ifndef HELIX_H
#define HELIX_H

#include <vector>

class Helix
{
public:
    Helix(long size);
    ~Helix();

    long size() { return m_size; }
    void drawHTL() { fillField(m_helixTL); }
    void drawHRT() { fillField(m_helixRT); }
    void drawHBR() { fillField(m_helixBR); }
    void drawHLB() { fillField(m_helixLB); }
    void drawHTR() { fillField(m_helixTR); }
    void drawHRB() { fillField(m_helixRB); }
    void drawHBL() { fillField(m_helixBL); }
    void drawHLT() { fillField(m_helixLT); }

    void printField();
    void clearField();

private:
    long m_size = 0;
    long ** m_helixTL = nullptr;
    long ** m_helixRT = nullptr;
    long ** m_helixBR = nullptr;
    long ** m_helixLB = nullptr;
    long ** m_helixTR = nullptr;
    long ** m_helixRB = nullptr;
    long ** m_helixBL = nullptr;
    long ** m_helixLT = nullptr;
    char ** m_field = nullptr;

    void fillField(long** m);
    void fillHTL();
    void fillHRT();
    void fillHBR();
    void fillHLB();
    void fillHTR();
    void fillHRB();
    void fillHBL();
    void fillHLT();

};

#endif // HELIX_H
