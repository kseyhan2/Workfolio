#include "universe.h"
#include "roketimiz.cpp"
#include <iostream>
#include <cmath>

Universe::Universe()
{
    head = NULL;
    size_ = 0;
    objectCache = NULL;
    blackHoleExists = false;
    blackHoleMass   = 0.0;
    blackHoleRadius = 0.0;
    blackHolePosition = vector2d(0,0);
}

Universe::~Universe()
{
    Node* current = head;
    while(current)
    {
        Node* temp = current->next;
        delete current->object;
        delete current;
        current = temp;
    }

    if(objectCache)
    {
        delete[] objectCache;
        objectCache = NULL;
    }
}

void Universe::insertCisim(double mass, const vector2d& pos, const vector2d& vel)
{
    cisim* yeni = new cisim(mass, pos, vel);

    Node* node = new Node;
    node->object = yeni;
    node->next = head;
    head = node;
    size_++;
}

void Universe::insertRoket(double mass, const vector2d& pos, const vector2d& vel,
                           const vector2d& thrustDir, double fuelRate)
{
    roket* yeni = new roket(mass, pos, vel, thrustDir, fuelRate);
    Node* node = new Node;
    node->object = yeni;
    node->next = head;
    head = node;
    size_++;
}

void Universe::createBlackHole(double mass, const vector2d& position, double radius)
{
    blackHoleExists   = true;
    blackHoleMass     = mass;
    blackHolePosition = position;
    blackHoleRadius   = radius;
}

void Universe::removeObject(purevirtual* obj)
{
    Node* prev = NULL;
    Node* curr = head;

    while (curr)
    {
        if (curr->object == obj)
        {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;

            delete curr->object;
            delete curr;
            size_--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}


void Universe::step()
{
    purevirtual** arr = getObjects();
    Node* iter = head;
    for(int i = 0; i < size_; i++)
    {
        iter->object->update(arr, size_);
        iter = iter->next;
    }

    applyBlackHoleEffect();
}

void Universe::applyBlackHoleEffect()
{
    if (!blackHoleExists) return;

    Node* iter = head;
    while (iter)
    {
        cisim* obj = dynamic_cast<cisim*>(iter->object);
        if (obj)
        {
           
            vector2d diff = obj->getkonum() - blackHolePosition;
            double dist = diff.vmagnitude();

            if (dist < blackHoleRadius)
            {
                if (spiralMap.find(obj) == spiralMap.end())
                {
                    SpiralData sd;
                    sd.started = true;
                    sd.r = dist;
                    sd.theta = std::atan2(diff.gety(), diff.getx());
                    spiralMap[obj] = sd;
                }
                applyLogSpiral(obj);
            }
            else
            {
                if (spiralMap.find(obj) != spiralMap.end())
                {
                    spiralMap.erase(obj);
                }
            }
        }
        iter = iter->next;
    }
}

void Universe::applyLogSpiral(cisim* obj)
{

    SpiralData& sd = spiralMap[obj];
    double k = 0.5; 
    double w = 2.0; 
    sd.r     = sd.r * std::exp(-k * dt);   
    sd.theta = sd.theta + w * dt;        
    double newX = blackHolePosition.getx() + sd.r * std::cos(sd.theta);
    double newY = blackHolePosition.gety() + sd.r * std::sin(sd.theta);
    obj->setkonum(vector2d(newX, newY));

}

purevirtual** Universe::getObjects() const
{
    if(objectCache)
    {
        delete[] objectCache;
        objectCache = NULL;
    }

    objectCache = new purevirtual*[size_];
    Node* iter = head;
    int i = 0;
    while(iter)
    {
        objectCache[i++] = iter->object;
        iter = iter->next;
    }

    return objectCache;
}

int Universe::getSize() const
{
    return size_;
}

