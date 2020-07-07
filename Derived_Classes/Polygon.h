/* 
 * File:   Polygon.h
 * Author: newjcc
 * Description: Polygon serves as a base, incomplete and to be
 *              built upon for future derived class.
 * Created on December 23, 2019, 1:04 AM
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
//#include <cmath>

class Polygon : public Shape{
public:
    Polygon();
    Polygon(int numberSides);
    Polygon(const Polygon& orig);
    
    virtual float get_perimeter() const = 0;
    virtual float get_area() const = 0;
    void set_numberSides(int numberSides);
    virtual int get_numberSides() const;
    
    friend std::ostream& operator << (std::ostream &out, const Polygon &polygon);
    friend std::istream& operator >> (std::istream &in, Polygon &polygon);
    
    virtual ~Polygon();
    
protected:
    Floatptr base, height;
    
private:
    int numberSides;
};

#endif /* POLYGON_H */