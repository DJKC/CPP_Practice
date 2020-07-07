/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: newjcc
 *
 * Created on August 27, 2019, 12:14 PM
 */

#ifndef ITEM_H
#define ITEM_H

#include <cstdlib>
#include <string>

class Item {
public:
    float statistics[12];
    std::string name;
    std::string item_class;
    
    Item();
    Item(const Item& orig);
    Item(std::string name, float statistics[], int number_statistics);
    Item& operator=(const Item&);
    friend std::ostream& operator<<(std::ostream &out, const Item &item);
    virtual ~Item();
    
    short item_index;
private:

};

#endif /* ITEM_H */

