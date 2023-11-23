//
// Created by Riley on 11/6/2023.
//
#include <iostream>
#include "SLList.h"

using namespace std;

int main() {
    SLList<string> linkedlist;
    linkedlist.push_back("nect value");
    linkedlist.push_back("your mom");
    linkedlist.push_back("heck yeah");
    linkedlist.print();

    linkedlist.remove(1);
    linkedlist.print();

    return(0);
}