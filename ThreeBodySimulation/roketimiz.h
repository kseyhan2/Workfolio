#ifndef ROKETIMIZ_H
#define ROKETIMIZ_H

#include "cismimiz.cpp"

class roket : public cisim
{
public:
    static int roketsayisi;

    roket();
    roket(const double& mkutle, const vector2d& mkonum, const vector2d& mhiz,
          const vector2d& thrustDir, double fuelRate);
    virtual ~roket() {}
    roket& operator=(const roket& r);
    virtual void kuvvethesapla(purevirtual** arr, int n);
    virtual void kutlehesapla();
    virtual void ivmehesapla();
    virtual void hizhesapla();
    virtual void konumhesapla();
    virtual void update(purevirtual** arr, int n);

protected:
    double   wp;  
    vector2d vp;  
};

#endif

