/* 
 * File:   Quadrilateral.h
 * Author: newjcc
 *
 * Created on December 23, 2019, 12:06 AM
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Polygon.h"

class Quadrilateral : public Polygon{
public:
    Quadrilateral();
    Quadrilateral(float side1, float side2, float side3, float side4);
    Quadrilateral(const Quadrilateral& orig);
    virtual float get_area() const = 0;
    float get_perimeter() const;
    
    friend std::ostream& operator << (std::ostream &out, const Quadrilateral &quadrilateral);
    friend std::istream& operator >> (std::istream &in, Quadrilateral &quadrilateral);
    
    virtual ~Quadrilateral();
private:

};

#endif /* QUADRILATERAL_H */

