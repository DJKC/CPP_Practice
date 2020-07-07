/* 
 * File:   Triangle.cpp
 * Author: newjcc
 * 
 * Created on December 23, 2019, 9:04 AM
 */

#include "Triangle.h"

Triangle::Triangle(){
    set_name("Triangle");
    set_numberSides(3);
    
    sides = new float[get_numberSides()];
}

Triangle::Triangle(float base, float height) : Triangle(){
    this->sides[0] =  set_positiveValue(base);
    this->base = &(sides[0]);
    
    this->sides[1] = set_positiveValue(height);
    this->height = &(sides[1]);
    
    this->sides[2] = find_thirdSide(*this);
}

Triangle::Triangle(float side1, float side2, float side3) : Triangle(){
    this->sides[0] = set_positiveValue(side1);
    this->sides[1] = set_positiveValue(side2);
    this->sides[2] = set_positiveValue(side3);
    
    this->base = &(sides[0]);
    this->height = &(sides[1]);
}

Triangle::Triangle(const Triangle& orig) : Triangle(){
    this->operator =(orig);
}

void Triangle::set_base(float base){
    *(this->base) = set_positiveValue(base);
}

void Triangle::set_height(float height){
    *(this->height) = set_positiveValue(height);
}

float Triangle::find_thirdSide(const Triangle &triangle){
    //F(x) needs works, not necessary at this moment.
    return 0.0f;
}

float Triangle::get_area() const{
   return (0.5f * (*base) * (*height));
}

float Triangle::get_perimeter() const{
    return (sides[0] + sides[1] + sides[2]);
}

Triangle& Triangle::operator =(const Triangle& triangle){
    if(this == &triangle){
        return *this;
    }
    
    sides[0] = triangle.sides[0];
    sides[1] = triangle.sides[1];
    sides[2] = triangle.sides[2];

    base = &(sides[0]);
    height = &(sides[1]);
    
    return (*this);
}

std::ostream& operator<< (std::ostream &out, const Triangle &triangle)
{
    // Since operator<< is a friend of the Triangle class, we can access Triangle's members directly.
    out << "\nThis shape is a " << triangle.get_name()
        << "\nThis is the abstract ancestor class, there no other values to show\n" << "\n\n";;
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Triangle &triangle)
{
    // Since operator<< is a friend of the Triangle class, we can access Triangle's members directly.
    std::cout << "\nThis shape is a " << triangle.get_name() << std::endl;
    
    int side1, side2, side3;
    
    //for(int i = 0; i < triangle.get_numberSides(); i++){}
    std::cout << "Enter base / side #1 of " << triangle.get_numberSides() << ": ";
    std::cin >> side1;
            
    std::cout << "Enter height / side #2 of " << triangle.get_numberSides() << ": ";
    std::cin >> side2;
 
    std::cout << "Enter side #3 of " << triangle.get_numberSides() << ": ";
    std::cin >> side3;
    
    //Triangle temp_triangle;
    triangle = Triangle(side1, side2, side3);
     
    return in;
}

Triangle::~Triangle(){
    delete [] sides;
    sides = nullptr;
}