/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: newjcc
 *
 * Created on December 23, 2019, 9:09 AM
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    Ellipse();
    Ellipse(const Ellipse& orig);
    virtual ~Ellipse();
    
    float perimeter();
    float area();
    int majorAxis;
    int minorAxis;
    int semi_majorAxis;
    int semi_minorAxis;
private:

};

#endif /* ELLIPSE_H */

