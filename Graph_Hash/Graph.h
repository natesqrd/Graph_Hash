//Everything has been written by Nathaniel Tucker
//except the hash, which came from lecuter and the depthFirst, which has only
//been slightly modified
#pragma once
#include <iostream>//cout endl
#include <vector>//vector<T>
#include <string>//string
#include "DLL.h"//addEnd node<T>{next, data} getHead print

using std::string;
using std::vector;

class Graph
{
private:
    //pointers
    //the pointers allow for dynamic array allocation within the class
    DblyLinkedList<string> *map;//Graph map to store source and destinaitons
    string *name;//holds source names in associated hash val position
    bool *visited;//holds bool var associated with source placement

    //array size
    int size;//non-const size for dynamic array initiation
             //this is used to caputed the number of edges in the main array and 
             //the location of the verticies by association
    int hash(string);
    void depthFirst(int);
    void falsify();
public:
    Graph(int);
    ~Graph();
    void addEdge(string, string);
    void depthFirstTrav(int);
    void depthBySource(string);
    int getIndex(string);
    bool searchName(string);
    void print();
};
