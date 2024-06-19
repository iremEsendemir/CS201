/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
*/

#ifndef Stack_h
#define Stack_h
#include "Cubicle.h"

class Stack{
public:
    Stack();
    ~Stack();
    void push(Cubicle* cubicle);
    void pop();
    Cubicle& peek();
    bool isEmpty() const;
    void print();
    void printReverseHelper(Cubicle* cubicle) const;
    void printReverse() const;
    

private:
   Cubicle* head;
};

#endif /* Stack_h */
