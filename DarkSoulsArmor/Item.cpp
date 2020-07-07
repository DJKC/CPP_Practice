/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: newjcc
 * 
 * Created on August 27, 2019, 12:14 PM
 */

#include "Item.h"
#include <cstdlib>
#include <iostream>

enum statistics{DURABILITY = 0, WEIGHT, STRIKE, SLASH, THRUST, MAGIC, FIRE, LIGHTNING, BLEED, POISON, CURSE, POISE};
static const int number_statistics = 12;
static std::string statistics_list[12] = {"Durability", "Weight", "Strike Protection", "Slash Protection",
                               "Thrust Protection", "Magic Protection", "Fire Protection",
                               "Lightning Protection", "Bleed Resistance", "Poison Resistance",
                               "Curse Resistance", "Poise Resistance"};

Item::Item(){
    name = "null";
    item_class = "null";
    
    for(int i = 0; i < number_statistics; i++){
        statistics[i] = 0.0;
    }
}

Item& Item::operator=(const Item &_item){
    this->name = _item.name;
    this->item_class = _item.item_class;
    
    for(int i = 0; i < number_statistics; i++){
        this->statistics[i] = _item.statistics[i];
    }
    
    return *this;
}

Item::Item(std::string _name, float statistics[], int number_statistics){
    this-> name = _name;
    
    for(int i = 0; i < number_statistics; i++){
        this->statistics[i] = statistics[i];
    }
    
    std::cout << "Name: " << this->name << std::endl;
    
    //don't need, just for checkig that it works
    for(int i = 0; i < 1; i++){
        std::cout << statistics_list[i] << ": " << this->statistics[i] << std::endl;
    }
    
    std::cout << std::endl;
}

Item::Item(const Item& orig){
    this->name = orig.name;
    
    for(int i = 0; i < number_statistics; i++){
        statistics[i] = orig.statistics[i];
    }
}

std::ostream& operator<<(std::ostream &out, const Item &item){
    out << "";
    
    return out;
}

Item::~Item(){
    
}

