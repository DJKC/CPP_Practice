/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: newjcc
 * 
 * Created on December 21, 2019, 10:30 PM
 */
1 //This is the implementation file Node.cpp.
2 //It implements logic for the Node class. The interface
3 //file is in the header file Node.h
4 #include <iostream>
5 #include "Node.h"
6
7 namespace linkedlistofclasses
8 {
9 Node::Node( ) : data(0), link(NULL)
10 {
11 //deliberately empty
12 }
13
14 Node::Node(int value, Node *next) : data(value), link(next)
15 {
16 //deliberately empty
17 }
18
19 //Accessor and Mutator methods follow
20
21 int Node::getData( ) const
22 {
23 return data;
24 }
25
26 Node* Node::getLink( ) const
27 {
28 return link;
29 }
30
31 void Node::setData(int value)
32 {
33 data = value;
34 }
35
36 void Node::setLink(Node *next)
37 {
38 link = next;
39 }
40 } //linkedlistofclasses
41 //Node.cpp