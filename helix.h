#ifndef HELIX_H
#define HELIX_H

#include <vector>

class Helix
{
public:
    Helix(long size);
    ~Helix();

    long size() { return m_size; }
    void drawHITL() { fillField(m_helixITL); }
    void drawHIRT() { fillField(m_helixIRT); }
    void drawHIBR() { fillField(m_helixIBR); }
    void drawHILB() { fillField(m_helixILB); }
    void drawHITR() { fillField(m_helixITR); }
    void drawHIRB() { fillField(m_helixIRB); }
    void drawHIBL() { fillField(m_helixIBL); }
    void drawHILT() { fillField(m_helixILT); }

    void printField();
    void clearField();

    long ** helixITL() const { return m_helixITL; }
    long ** helixIRT() const { return m_helixIRT; }
    long ** helixIBR() const { return m_helixIBR; }
    long ** helixILB() const { return m_helixILB; }
    long ** helixITR() const { return m_helixITR; }
    long ** helixIRB() const { return m_helixIRB; }
    long ** helixIBL() const { return m_helixIBL; }
    long ** helixILT() const { return m_helixILT; }


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

    char ** m_field = nullptr;

    void fillField(long** m);
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
