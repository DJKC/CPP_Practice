/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: newjcc
 *
 * Created on August 27, 2019, 12:16 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"

class Player {
public:
    const static short number_left_hand_weapons_slots = 2;
    const static short number_right_hand_weapons_slots = 2;
    const static short number_rings_slots = 2;
    const static short number_single_use_items_slots = 5;
    const static short number_bolt_slots = 2;
    const static short number_arrow_slots = 2;
    
    Item left_hand[number_left_hand_weapons_slots];
    Item right_hand[number_right_hand_weapons_slots];
    Item rings[number_rings_slots];
    
    Item armor;
    Item helmet;
    Item guantlets;
    Item leggings;
    
    std::string name;
    
    Player();
    Player(const Player& orig);
    friend std::ostream& operator<<(std::ostream &out, const Player &player);
    
    bool is_empty(Item);
    int number_empty(Item item_array[], int size);
    bool equip_Item(Item item, int slot_number, char which_container = 'R');
    bool unequip_Item(Item item, int slot_number, char which_slot = 's');
    bool unequip_Item(Item *item);
    bool swap_Item(Item &old_Item, Item &new_Item);
    
    virtual ~Player();
private:

};

#endif /* PLAYER_H */

