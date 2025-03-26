#include "cismimiz.h"

int cisim::cisimsayisi = 0;

cisim::cisim(const double& mkutle, const vector2d& mkonum, const vector2d& mhiz)
{
    cisimsayisi++;
    kutle       = new double(mkutle);
    konum       = new vector2d(mkonum);
    hiz         = new vector2d(mhiz);
    totalforce  = new vector2d(0, 0);
    ivme        = new vector2d(0, 0);
}

cisim::cisim()
{
    cisimsayisi++;
    kutle       = new double(0);
    konum       = new vector2d(0,0);
    hiz         = new vector2d(0,0);
    totalforce  = new vector2d(0, 0);
    ivme        = new vector2d(0, 0);
}

cisim::cisim(const cisim& other)
{
    cisimsayisi++;
    kutle       = new double(*other.kutle);
    konum       = new vector2d(*other.konum);
    hiz         = new vector2d(*other.hiz);
    totalforce  = new vector2d(*other.totalforce);
    ivme        = new vector2d(*other.ivme);
}

cisim::~cisim()
{
    cisimsayisi--;
    delete kutle;
    delete konum;
    delete hiz;
    delete totalforce;
    delete ivme;
}


void cisim::kuvvethesapla(purevirtual** arr, int n)
{
    totalforce->setx(0);
    totalforce->sety(0);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == this) 
            continue;

        cisim* other = dynamic_cast<cisim*>(arr[i]);
        if(!other) 
            continue;

        vector2d diff = this->getkonum() - other->getkonum();
        double r = diff.vmagnitude();
        if(r == 0) 
            continue; 

        double forceVal = -G * this->getkutle() * other->getkutle() / (r*r*r);
        vector2d force = diff * forceVal;

        *totalforce = *totalforce + force;
    }
}

void cisim::ivmehesapla()
{
    double m = this->getkutle();
    if(m <= 0) 
        return;

    vector2d accel = (*totalforce) / m;
    ivme->setx(accel.getx());
    ivme->sety(accel.gety());
}

void cisim::hizhesapla()
{
    vector2d deltaV = (*ivme) * dt;
    *hiz = *hiz + deltaV;
}

void cisim::konumhesapla()
{
    vector2d deltaPos = (*hiz) * dt;
    *konum = *konum + deltaPos;
}

void cisim::update(purevirtual** arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cisim* c = dynamic_cast<cisim*>(arr[i]);
        if(!c) 
            continue;

        c->kuvvethesapla(arr, n);
        c->ivmehesapla();
        c->hizhesapla();
        c->konumhesapla();
    }
}


void cisim::kutlehesapla()
{
    
}

void cisim::settf(vector2d force)
{
    totalforce->setx(force.getx());
    totalforce->sety(force.gety());
}

vector2d cisim::gettf() const
{
    return *totalforce;
}

double cisim::getkutle() const
{
    return *kutle;
}

vector2d cisim::getkonum() const
{
    return *konum;
}

vector2d cisim::gethiz() const
{
    return *hiz;
}

void cisim::sethiz(const vector2d& v)
{
    hiz->setx(v.getx());
    hiz->sety(v.gety());
}


void cisim::setkutle(double m)
{
    *kutle = m;
}


void cisim::setkonum(const vector2d& p)
{
    konum->setx(p.getx());
    konum->sety(p.gety());
}

