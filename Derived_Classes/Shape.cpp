/* 
 * File:   Form.cpp
 * Author: newjcc
 * RH179753KC
 * 
 * Created on December 22, 2019, 11:54 PM
 */

#include "Shape.h"

Shape::Shape(){
    name = "Shape";
}

Shape::Shape(const Shape& orig) : Shape(){
}

void Shape::set_name(std::string name){
    this->name = name;
}

std::string Shape::get_name() const{
    return name;
}

std::ostream& operator<< (std::ostream &out, const Shape &shape)
{
    // Since operator<< is a friend of the Shape class, we can access Shape's members directly.
    out << "\nThis shape is a " << shape.get_name() << std::endl
        << "This is the abstract ancestor class, there no other values to show" << "\n\n";;
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Shape &shape)
{
    // Since operator<< is a friend of the Shape class, we can access Shape's members directly.
    std::cout << "\nThis shape is a " << shape.get_name() << std::endl
        << "This is the abstract ancestor class, there no other values to show"
        << std::endl << "There are no values that need input.";
 
    return in;
}

Shape::~Shape(){}

//https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
//There is a way to use template fucntions in cpp file
//template T Shape::Shape<int>();
//template T Shape<float>();