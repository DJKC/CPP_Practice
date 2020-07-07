/* 
 * File:   RightTriangle.cpp
 * Author: newjcc
 * 
 * Created on January 26, 2020, 7:56 PM
 */

#include <cmath>
#include "RightTriangle.h"

RightTriangle::RightTriangle(){
    set_name("Right Triangle");
    set_numberSides(3);
    
    sides = new float[get_numberSides()];
}

RightTriangle::RightTriangle(float side1, float side2, char &which_side) : RightTriangle(){
    if(which_side == 'Y'){
        this->sides[0] = set_positiveValue(side1);
        this->base = &(sides[0]);

        this->sides[1] = set_positiveValue(side2);
        this->height = &(sides[1]);
        
        hypotenuse = &(this->sides[2] = sqrtf((side1 * side1) + (side2 * side2)));
    }else{
        hypotenuse = &(this->sides[2] = (side1 > side2 ? side1 : side2));
        
        float temp_side = side2 > side1 ? side1 : side2;
        
        if(which_side == 'b'){
            height = &(this->sides[1] = temp_side);
            base = &(this->sides[0] = sqrtf(((*hypotenuse) * (*hypotenuse)) - ((*height) * (*height))));
        }else if(which_side == 'h'){
            base = &(this->sides[1] = temp_side);
            height = &(this->sides[0] = sqrtf(((*hypotenuse) * (*hypotenuse)) - ((*base) * (*base))));
        }else{
            std::cout << "\nIncorrect third parameter, now exiting\n";
            
            std::exit(0);
        }
    }
}

RightTriangle::RightTriangle(float base, float height, float hypotenuse) : RightTriangle(){
    this->sides[0] = set_positiveValue(base);
    this->sides[1] = set_positiveValue(height);
    this->sides[2] = set_positiveValue(hypotenuse);
    
    this->base = &(sides[0]);
    this->height = &(sides[1]);
    this->hypotenuse = &(sides[2]);
}

RightTriangle::RightTriangle(const RightTriangle& orig) : RightTriangle(){
    this->operator = (orig);
}

RightTriangle& RightTriangle::operator =(const RightTriangle& right_triangle){
    if(this == &right_triangle){
        return *this;
    }
    
    sides[0] = right_triangle.sides[0];
    sides[1] = right_triangle.sides[1];
    sides[2] = right_triangle.sides[2];

    base = &(sides[0]);
    height = &(sides[1]);
    
    return (*this);
}

//Below f(x) needs work, may delete or more than likely refactor.
float RightTriangle::find_thirdSide(const Triangle &triangle){
    
    return 0.0f;
}

std::ostream& operator<< (std::ostream &out, const RightTriangle &right_triangle){
    // Since operator<< is a friend of the RightTriangle class, we can access RightTriangle's members directly.
    out << "\nThis shape is a " << right_triangle.get_name()
        << "\nPerimeter: " << right_triangle.get_perimeter()
        << "\nArea: " << right_triangle.get_area()
        << "\nValue of the base: " << *(right_triangle.base)
        << "\nValue of the height: " << *(right_triangle.height)
        << "\nValue of the hypotenuse: " << *(right_triangle.hypotenuse) << "\n\n";
    
    return out;
}
 
std::istream& operator>> (std::istream &in, RightTriangle &right_triangle){
    // Since operator<< is a friend of the RightTriangle class, we can access RightTriangle's members directly.
    std::cout << "\nThis shape is a " << right_triangle.get_name() << std::endl;
    
    int side1, side2, side3;
    
    //for(int i = 0; i < right_triangle.get_numberSides(); i++){}
    std::cout << "Enter base / side #1 of " << right_triangle.get_numberSides() << ": ";
    std::cin >> side1;
            
    std::cout << "Enter height / side #2 of " << right_triangle.get_numberSides() << ": ";
    std::cin >> side2;
 
    std::cout << "Enter side #3 of " << right_triangle.get_numberSides() << ": ";
    std::cin >> side3;
    
    //RightTriangle temp_right_triangle;
    right_triangle = RightTriangle(side1, side2, side3);
     
    return in;
}

RightTriangle::~RightTriangle(){
    delete [] sides;
    sides = nullptr;
}