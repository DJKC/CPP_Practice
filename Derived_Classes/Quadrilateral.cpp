/* 
 * File:   Quadrilateral.cpp
 * Author: newjcc
 * 
 * Created on December 23, 2019, 12:06 AM
 */

#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(){
   set_name("Quadrilateral");
   set_numberSides(4);
   
   sides = new float[get_numberSides()];
}

Quadrilateral::Quadrilateral(float side1, float side2, float side3, float side4) : Quadrilateral(){
    this->sides[0] = set_positiveValue(side1);
    this->sides[1] = set_positiveValue(side2);
    this->sides[2] = set_positiveValue(side3);
    this->sides[3] = set_positiveValue(side4);
}

Quadrilateral::Quadrilateral(const Quadrilateral& orig) : Quadrilateral(){
    sides[0] = orig.sides[0];
    sides[1] = orig.sides[1];
    sides[2] = orig.sides[2];
    sides[3] = orig.sides[3];
}

float Quadrilateral::get_area() const{
    return 0.0f;
}

float Quadrilateral::get_perimeter() const {
    return (sides[0] + sides[1] + sides[2] + sides[3]);
}

std::ostream& operator<< (std::ostream &out, const Quadrilateral &quadrilateral)
{
    // Since operator<< is a friend of the Quadrilateral class, we can access Quadrilateral's members directly.
    out << "\nThis shape is a " << quadrilateral.get_name()
        << "\nThis is the abstract ancestor class, there no other values to show" << "\n\n";;
 
    return out;
}

std::istream& operator>> (std::istream &in, Quadrilateral &quadrilateral)
{
    // Since operator<< is a friend of the Quadrilateral class, we can access Quadrilateral's members directly.
    std::cout << "\nThis shape is a " << quadrilateral.get_name() << std::endl
              << "This is the abstract ancestor class, there no other values to show"
              << "\nThere are no values that need input.";
 
    return in;
}

Quadrilateral::~Quadrilateral(){
    delete [] sides;
    sides = nullptr;
}

