/* 
 * File:   RightTriangle.h
 * Author: newjcc
 *
 * Created on January 26, 2020, 7:56 PM
 */

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle{
public:
    RightTriangle();
    RightTriangle(float base, float height, char &which_side);
    RightTriangle(float side1, float side2, float side3);
    RightTriangle(const RightTriangle& orig);
    
    RightTriangle& operator = (const RightTriangle &triangle);
    friend std::ostream& operator << (std::ostream &out, const RightTriangle &right_triangle);
    friend std::istream& operator >> (std::istream &in, RightTriangle &right_triangle);
    
    virtual ~RightTriangle();
    
protected:
    Floatptr hypotenuse;
    
private:
    float find_thirdSide(const Triangle &triangle);
};



#endif /* RIGHTTRIANGLE_H */
