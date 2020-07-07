/* 
 * File:   Triangle.h
 * Author: newjcc
 *
 * Created on December 23, 2019, 9:04 AM
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon{
public:
    Triangle();
    Triangle(float base, float height);
    Triangle(float base, float height, float hypotensue);
    Triangle(const Triangle& orig);
    
    float get_perimeter() const;
    virtual float get_area() const;
    float get_side(int sideNumber);
    void set_base(float base);
    void set_height(float height);
    
    Triangle& operator = (const Triangle &triangle);
    
    friend std::ostream& operator << (std::ostream &out, const Triangle &triangle);
    friend std::istream& operator >> (std::istream &in, Triangle &triangle);
    
    virtual ~Triangle();

private:
    virtual float find_thirdSide(const Triangle &triangle);
};

#endif /* TRIANGLE_H */

