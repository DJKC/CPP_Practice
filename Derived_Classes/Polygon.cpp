/* 
 * File:   Polygon.cpp
 * Author: newjcc
 * 
 * Created on December 23, 2019, 1:04 AM
 */

#include "Polygon.h"

Polygon::Polygon() : Shape(){
    this->set_name("Polygon");
}

Polygon::Polygon(int numberSides) : Polygon(){
    set_numberSides(numberSides);
}

Polygon::Polygon(const Polygon& orig) : Polygon(){
    //No code needed here because no Polygon objects will created.
}

float Polygon::get_area() const {return 0.0f;}
//Polygon object is non existent, area will not be calculated.
//Area will be calculated in the next derived non abstract class.

float Polygon::get_perimeter() const {return 0.0f;}
//Polygon object is non existent, perimeter will not be calculated.
//Perimeter will be calculated in the next derived non abstract class.

void Polygon::set_numberSides(int numberSides){
    this->numberSides = set_positiveValue(numberSides);
    sides = new float[this->numberSides];
}

int Polygon::get_numberSides() const{
    return numberSides;
}
 
std::ostream& operator<< (std::ostream &out, const Polygon &polygon)
{
    // Since operator<< is a friend of the Polygon class, we can access Polygon's members directly.
    out << "\nThis shape is a " << polygon.get_name() << std::endl
        << "This is the abstract ancestor class, there no other values to show" << "\n\n";
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Polygon &polygon)
{
    // Since operator<< is a friend of the Polygon class, we can access Polygon's members directly.
    std::cout << "This shape is a " << polygon.get_name() << std::endl
        << "This is the abstract ancestor class, there no other values to show"
        << std::endl << "There are no values that need input.";
 
    return in;
}

Polygon::~Polygon(){
    delete [] sides;
    sides = nullptr;
}

