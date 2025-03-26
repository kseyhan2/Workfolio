#ifndef PUREVIRTUAL_H
#define PUREVIRTUAL_H
#include "vector.h"

class purevirtual
{
public:

    virtual ~purevirtual() {}
    virtual void kuvvethesapla(purevirtual** arr, int n) = 0;
    virtual void ivmehesapla()                           = 0;
    virtual void hizhesapla()                            = 0;
    virtual void konumhesapla()                          = 0;
    virtual void update(purevirtual** arr, int n)        = 0;
    virtual void       settf(vector2d force)       = 0;
    virtual vector2d   gettf()               const = 0;
    virtual double     getkutle()            const = 0;
    virtual vector2d   getkonum()            const = 0;
    virtual vector2d   gethiz()              const = 0;
    virtual void       kutlehesapla()              = 0;
};

#endif

