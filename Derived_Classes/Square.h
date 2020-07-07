/* 
 * File:   Square.h
 * Author: newjcc
 *
 * Created on December 23, 2019, 12:12 AM
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Quadrilateral.h"

class Square : public Quadrilateral{
public:
    Square();
    Square(const Square& orig);
    Square(float side);

    float get_area() const;
    float get_side() const;

    friend std::ostream& operator << (std::ostream &out, const Square &square);
    friend std::istream& operator >> (std::istream &in, Square &square);
    
    virtual ~Square();
private:

};

#endif /* SQUARE_H */