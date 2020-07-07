/* 
 * File:   Shape.h
 * Author: newjcc
 * Description: Shape is the bottom most class in
 *              the hierarchy of shapes, the ancestor.
 *
 * Created on December 22, 2019, 11:54 PM
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

typedef float* Floatptr;
typedef int* Intptr;

class Shape {
public:
    Shape();
    Shape(const Shape& orig);
    
    virtual void set_name(std::string);
    virtual std::string get_name() const;
    
    friend std::ostream& operator << (std::ostream &out, const Shape &shape);
    friend std::istream& operator >> (std::istream &in, Shape &shape);
    
    virtual ~Shape();
    
protected:
    template<typename T>
    T set_positiveValue(T value){
        do{
            if(value > 0){
                return value;
            }else{
                std::cout << std::endl << "Value should be greater than zero, try again: ";
                std::cin >> value;            
            }
        }while(true);
    }
    

protected:
    Floatptr sides;

private:
    std::string name;
    //char *name;
};



#endif /* SHAPE_H */
