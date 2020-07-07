/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.cpp
 * Author: newjcc
 * 
 * Created on December 23, 2019, 12:12 AM
 */

#include "Square.h"

Square::Square(){
   set_name("Square");
   set_numberSides(4);
   
   sides = new float[get_numberSides()];
}

Square::Square(float side) : Square(){
    for(int i = 0; i < this->get_numberSides(); i++){
        this->sides[i] = set_positiveValue(side);
    }
}

Square::Square(const Square& orig) : Square(){
    sides[0] = orig.sides[0];
    sides[1] = orig.sides[1];
    sides[2] = orig.sides[2];
    sides[3] = orig.sides[3];
}

float Square::get_side() const{
    return this->sides[0];
}

float Square::get_area() const{
    return (this->get_numberSides() * this->get_numberSides());
}

std::ostream& operator<< (std::ostream &out, const Square &square)
{
    // Since operator<< is a friend of the Square class, we can access Square's members directly.
    out << "\nThis shape is a " << square.get_name()
        << "\nNumber of sides: " << square.get_numberSides()
        << "\nValue of each side: " << square.get_side()
        << "\nPerimeter: " << square.get_perimeter()
        << "\nArea: " << square.get_area() << "\n\n";;

    return out;
}

std::istream& operator>> (std::istream &in, Square &square)
{
    int side;
    // Since operator<< is a friend of the Square class, we can access Square's members directly.
    std::cout << "\nThis shape is a " << square.get_name()
              << "\nEnter the value of the side: ";
    std::cin >> side;
    
    square = Square(side);
 
    return in;
}

Square::~Square() {
}

