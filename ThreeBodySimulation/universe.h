#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "purevirtual.h"
#include "cismimiz.h"
#include "vector.h"
#include <map> 


struct SpiralData {
    bool   started;  
    double r;       
    double theta;   
};

class Universe
{
public:

    Universe();
    ~Universe();
    void insertCisim(double mass, const vector2d& pos, const vector2d& vel);
    void insertRoket(double mass, const vector2d& pos, const vector2d& vel,
                     const vector2d& thrustDir, double fuelRate);

    void createBlackHole(double mass, const vector2d& position, double radius);
    void step();
    purevirtual** getObjects() const;
    int getSize() const;
    void removeObject(purevirtual* obj);

private:
    
    struct Node
    {
        purevirtual* object;
        Node* next;
    };

    Node* head;
    int size_;
    mutable purevirtual** objectCache;
    bool    blackHoleExists;
    double  blackHoleMass;
    double  blackHoleRadius;
    vector2d blackHolePosition;
    std::map<purevirtual*, SpiralData> spiralMap;

private:

    void applyBlackHoleEffect();
    void applyLogSpiral(cisim* obj);
    Universe(const Universe&);
    Universe& operator=(const Universe&);
};

#endif

