#ifndef VECTOR_H
#define VECTOR_H
#define G  1.0   
#define dt 0.012 


class vector2d

{
public:

    vector2d();
    vector2d(double xVal, double yVal);
    vector2d(const vector2d& other);
    ~vector2d();
    double getx() const;
    double gety() const;
    void   setx(double val);
    void   sety(double val);
    double vmagnitude() const;
    vector2d operator+(const vector2d& rhs) const;
    vector2d operator-(const vector2d& rhs) const;
    vector2d operator*(double scalar)       const;
    vector2d operator/(double scalar)       const;
    vector2d& operator=(const vector2d& rhs);

private:

    double* px;
    double* py;
};

#endif

