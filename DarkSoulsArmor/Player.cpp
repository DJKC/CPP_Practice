
/* 
 * File:   Player.cpp
 * Author: newjcc
 * 
 * Created on August 27, 2019, 12:16 PM
 * Player has slots for
 *  two left hand weapons
 *  two right hand weapons
 *  one helmet 
 *  one armor
 *  one gauntlet
 *  one leggings
 *  two rings
 */

#include "Player.h"
#include "Item.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Player::Player(){
    this->name = "null";
    
    Item left_hand[number_left_hand_weapons_slots],
         right_hand[number_right_hand_weapons_slots],
         rings[number_rings_slots],
         armor, guantlets, leggings, helmet;
}

Player::Player(const Player& orig){
    this->name = orig.name;
    
    for(short i = 0; i < number_left_hand_weapons_slots; i++){
        this->left_hand[i] = orig.left_hand[i];
    }
    
    for(short i = 0; i < number_right_hand_weapons_slots; i++){
        this->right_hand[i] = orig.right_hand[i];
    }
    
    for(short i = 0; i < this->number_rings_slots; i++){
        this->rings[i] = orig.rings[i];
    }

    this->helmet = orig.helmet;
    this->armor = orig.armor;
    this->guantlets = orig.guantlets;
    this->leggings = orig.leggings;
}

bool Player::is_empty(Item item){
    if(item.name == "null"){
        return false;
    }else{
        return true;
    }
}

int Player::number_empty(Item item_array[], int size){
    int count = 0;
    
    for(int i = 0; i < size; i++){
        if(item_array[i].name == "null"){
            count++;
        }
    }
    
    return count;
}

//I can pass in the pointer tothe array to make this section shorter
bool Player::equip_Item(Item new_item, int slot_number = 0, char which_container){
    bool equipped = true;
    
    if(which_container == 'L'){
        this->left_hand[slot_number] = new_item;
    }else if(which_container == 'R'){
        this->right_hand[slot_number] = new_item;
    }else if(which_container == 'r'){
        this->rings[slot_number] = new_item;
    }else if(which_container == 'a'){
        this->armor = new_item;
    }else if(which_container == 'h'){
        this->helmet = new_item;
    }else if(which_container == 'g'){
        this->guantlets = new_item;
    }else if(which_container == 'l'){
        this->leggings = new_item;
    }else{
        std::cout << endl << "Item not equppied" << endl;
        equipped = false;
    }
    
    return equipped;
}

//I can pass in the pointer tothe array to make this section shorter
bool Player::unequip_Item(Item _item, int slot_number = 0, char which_container){
    bool equipped = true;
    
    if(which_container == 'L'){
        this->left_hand[slot_number].name = "null";
    }else if(which_container == 'R'){
        this->right_hand[slot_number].name = "null";
    }else if(which_container == 'r'){
        this->rings[slot_number].name = "null";
    }else if(which_container == 'a'){
        this->armor.name = "null";
    }else if(which_container == 'h'){
        this->helmet.name = "null";
    }else if(which_container == 'g'){
        this->guantlets.name = "null";
    }else if(which_container == 'l'){
        this->leggings.name = "null";
    }else{
        std::cout << endl << "Item not unequppied" << endl;
        equipped = false;
    }
    
    return equipped;
}

bool Player::unequip_Item(Item *_item){

    Item *item = _item;
    
    item->name = "null";

    return true;
}

bool Player::swap_Item(Item &item1, Item &item2){
    if(item1.name != "null" & item2.name != "null"){
        std::string name = item1.item_class;
        item1.item_class = item2.item_class;
        item2.item_class = name;

        name = item1.name;
        item1.name = item2.name;
        item2.name = name;

        return true;
    }else{
        return false;
    }
}

std::ostream& operator<<(std::ostream &out, const Player &player){
    out << "Player's name is " << player.name << endl
        << "Character stats will come here" << endl
        << "Left hand weapons: " << player.left_hand[0].name << " & " << player.left_hand[1].name << endl
        << "Right hand weapns: " << player.right_hand[0].name << " & " << player.right_hand[1].name << endl
        << "Rings: " << player.rings[0].name << " & " << player.rings[1].name << endl
        << "Helmet: " << player.helmet.name << endl
        << "Armor: " << player.armor.name << endl
        << "Guantlets: " << player.guantlets.name << endl
        << "Leggings: " << player.leggings.name << endl;
    
    return out;
}

Player::~Player(){
}

