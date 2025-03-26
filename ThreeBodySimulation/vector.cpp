#include "vector.h"
#include <cmath>

vector2d::vector2d()
{
    px = new double(0);
    py = new double(0);
}

vector2d::vector2d(double xVal, double yVal)
{
    px = new double(xVal);
    py = new double(yVal);
}

vector2d::vector2d(const vector2d& other)
{
    px = new double(*other.px);
    py = new double(*other.py);
}

vector2d::~vector2d()
{
    delete px;
    delete py;
}

double vector2d::getx() const
{
    return *px;
}

double vector2d::gety() const
{
    return *py;
}

void vector2d::setx(double val)
{
    *px = val;
}

void vector2d::sety(double val)
{
    *py = val;
}

double vector2d::vmagnitude() const
{
    return std::sqrt((*px)*(*px) + (*py)*(*py));
}

vector2d vector2d::operator+(const vector2d& rhs) const
{
    vector2d result;
    result.setx(this->getx() + rhs.getx());
    result.sety(this->gety() + rhs.gety());
    return result;
}

vector2d vector2d::operator-(const vector2d& rhs) const
{
    vector2d result;
    result.setx(this->getx() - rhs.getx());
    result.sety(this->gety() - rhs.gety());
    return result;
}

vector2d vector2d::operator*(double scalar) const
{
    vector2d result;
    result.setx(this->getx() * scalar);
    result.sety(this->gety() * scalar);
    return result;
}

vector2d vector2d::operator/(double scalar) const
{
    vector2d result;
    result.setx(this->getx() / scalar);
    result.sety(this->gety() / scalar);
    return result;
}

vector2d& vector2d::operator=(const vector2d& rhs)
{
    if(this == &rhs) return *this;
    this->setx(rhs.getx());
    this->sety(rhs.gety());
    return *this;
}

