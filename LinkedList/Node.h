
/* 
 * File:   Node.h
 * Author: newjcc
 *
 * Created on December 21, 2019, 10:30 PM
 */
1 //This is the header file for Node.h. This is the interface for
2 //a node class that behaves similarly to the struct defined
3 //in Display 13.4
4 namespace linkedlistofclasses
5 {
6 class Node
7 {
8 public:
9 Node( );
10 Node(int value, Node *next);
11 //Constructors to initialize a node
12
13 int getData( ) const;
14 //Retrieve value for this node
15
16 Node *getLink( ) const;
17 //Retrieve next Node in the list
18
19 void setData(int value);
20 //Use to modify the value stored in the list
21
22 void setLink(Node *next);
23 //Use to change the reference to the next node
24
25 private:
26 int data;
27 Node *link;
28 };
29 typedef Node* NodePtr;
30 } //linkedlistofclasses
31 //Node.h
