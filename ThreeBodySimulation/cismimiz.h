#ifndef CISIM_H
#define CISIM_H

#include "purevirtual.cpp"
#include "vector.cpp"
#include <iostream>

class cisim : public purevirtual
{
public:
    static int cisimsayisi;

    cisim(const double& mkutle, const vector2d& mkonum, const vector2d& mhiz);
    cisim();
    cisim(const cisim& other);
    virtual ~cisim();

    virtual void kuvvethesapla(purevirtual** arr, int n);
    virtual void ivmehesapla();
    virtual void hizhesapla();
    virtual void konumhesapla();
    virtual void update(purevirtual** arr, int n);
    virtual void       settf(vector2d force);
    virtual vector2d   gettf()       const;
    virtual double     getkutle()    const;
    virtual vector2d   getkonum()    const;
    virtual vector2d   gethiz()      const;
    virtual void       kutlehesapla();
    virtual void sethiz(const vector2d& v);
    virtual void setkutle(double m);
    virtual void setkonum(const vector2d& p);

protected:
    double*   kutle;       
    vector2d* konum;       
    vector2d* hiz;         
    vector2d* totalforce;  
    vector2d* ivme;        
};

#endif

