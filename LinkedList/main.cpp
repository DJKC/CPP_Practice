/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on December 21, 2019, 9:09 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *link;
};

typedef Node* NodePtr;

void insertHead(){
    
}

int main(int argc, char** argv) {
    Node node1{1, NULL};
    Node node2{2, NULL};
    Node node3{3, NULL};

    NodePtr head = &node1;
    node1.link = &node2;
    node2.link = &node3;
    
    for(NodePtr i = head; i->link != nullptr; i = i->link){
        cout << i->data << endl;
    }
    
    return 0;
}
