#include "roketimiz.h"
#include <iostream>

int roket::roketsayisi = 0;

roket::roket()
    : cisim()
{
    roketsayisi++;
    wp = 0.0;
    vp = vector2d(0,0);
}

roket::roket(const double& mkutle, const vector2d& mkonum, const vector2d& mhiz,
             const vector2d& thrustDir, double fuelRate)
    : cisim(mkutle, mkonum, mhiz)
{
    roketsayisi++;
    vp = thrustDir;
    wp = fuelRate;
}

roket& roket::operator=(const roket& r)
{
    if(this == &r) 
        return *this;

    *(this->kutle)      = r.getkutle();
    *(this->konum)      = r.getkonum();
    *(this->hiz)        = r.gethiz();
    *(this->ivme)       = *(r.ivme);
    *(this->totalforce) = r.gettf();
    this->wp = r.wp;
    this->vp = r.vp;
    return *this;
}


void roket::kutlehesapla()
{
    *(this->kutle) = *(this->kutle) - wp * dt;
    if(*(this->kutle) < 0)
        *(this->kutle) = 0;
}

void roket::kuvvethesapla(purevirtual** arr, int n)
{
    
    this->kutlehesapla();
    cisim::kuvvethesapla(arr, n);
    vector2d thrust = vp * wp; 
    vector2d curF = this->gettf();
    vector2d newF = curF - thrust;
    this->settf(newF);
}

void roket::ivmehesapla()
{
    cisim::ivmehesapla();
}

void roket::hizhesapla()
{
    cisim::hizhesapla();
}

void roket::konumhesapla()
{
    cisim::konumhesapla();
}


void roket::update(purevirtual** arr, int n)
{
    cisim::update(arr, n);
}

