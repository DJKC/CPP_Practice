/*
 * Description: How to Make Pollo Guisado
 */

/* 
 * File:   main.cpp
 * Author: Stella
 *
 * Created on November 2, 2019, 10:43 PM
 */

//#include <cstdlib>
#include <iostream>
using namespace std;

/*
 how to make pollo guisado
    -gather ingredients
        boneless, skinless, chicken breast or thigh
        sazon
        adobo
        pepper and onion blend(fresh or frozen)
        cumin
        thyme
        red or russett potatoes
        oregano
        garlic powder/garlic gloves
        parsley
        pepper
        salt
        white rice(any grain)
        cooking oil
        sofrito(if you like the taste-homemade or store bought)
     -boil water
     -peel potatoes while water boils
     -lightly season potatoes with salt and pepper to taste
     -cut chicken breasts into 2-3 smaller pieces each
     -lightly season when done
     -place chicken pieces in boiling water
     -let cook for 10 minutes
     -add sazon for flavor and reddish coloring
     -add adobo, cumin, thyme and stir
     -let cook on medium-low heat for 30 minutes
     -peel, crush, and mince garlic if making fresh
     -add garlic powder and minced garlic
     -add sofrito
     -add parsley and oregano
     -add peeled potatoes and then stir
     -let sit for 30 minutes
     -add pepper and onion blend and then stir
     -let sit for 45-50 more minutes until flavors are pronounced and chicken breasts are tender
     -put rice in another pot
     -add water an inch above the line of rice
     -add salt and oil to water and rice and then stir
     -turn high heat for 6 minutes and put a top on pot
     -turn to medium heat and stir
     -repeat as needed to ensure full cooking of rice and minimal burning
     -once rice is soft, place on low heat to keep warm but not overcook or burn rice
     -get a plate from cabinet
     -use serveware to get pieces of the pollo guisado and rice onto plate
     -let sit for 2-5 minutes
     -sit in your desired place of dining and enjoy your meal.
    
 */



void add_ingredient(string ingredient){
    
    cout << ingredient << "Has been added" ;
    return;
    
}

int main(int argc, char** argv) {
    short pin, number=2, number2;
    float decimal ;
    bool ye_not_guilty; 
    string guilty_message="Die!";
    string ingredient1="ketchup", ingredient2= "cheese" ,ingredient3="pickles";
            
    string user_text;
    bool true_or_false;
    char character = 'a';
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'}, jibberish[10] = {"ABCDEFGHI"};
    int number_array[3] = {1000, 1002020, 2333};
    
    true_or_false = !(false);
    char_array[0] = 55 * 2;
    
    cout << "*" << char_array[0] << "*" << endl;
    
//    cout << "Enter some text: ";
//    cin >> user_text;
//    
//    if(strcmp(user_text.c_str(), "momma") == 0){
//        cout << "But where's dad?";
//                
//        return 80;
//    }else{
//        return 99;
//    }     
    
    /*cout << "Pick your pin: ";
    cin >> pin;
    cout << "Your pin is " << pin << endl;
    
    cout << "Pick your decimal: " ;
    cin >> decimal; 
    cout << decimal << endl ; 
    
    
    ye_not_guilty=true; 
    
    if(ye_not_guilty==false){
        cout << "Not guilty" ;
    }
    if(ye_not_guilty==true){
        cout << guilty_message ;
     */
    
    
        
add_ingredient(ingredient1);
add_ingredient(ingredient2);
add_ingredient(ingredient3);

    
    return 0;
}

