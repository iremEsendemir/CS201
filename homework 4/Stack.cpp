/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
*/

#include "Stack.h"
#include <iostream>
#include "Cubicle.h"
Stack::Stack() : head(nullptr) {}
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}
void Stack::push(Cubicle* cubicle) {
    cubicle->next = head;
    head = cubicle;
}
void Stack::pop() {
    if (isEmpty()) {
        std::cout << "It is empty, cannot be popped.";
        return;
    }
    head->visited = 0;
    head = head->next;
}

void Stack::print(){
    Cubicle* temp = head;
        while (temp != nullptr) {
            std::cout << "(" << temp->row << "," << temp->col << ")";
            if (temp->next != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
}
void Stack::printReverseHelper(Cubicle* cubicle) const {
    if (cubicle == nullptr) return;
    printReverseHelper(cubicle->next);
    std::cout << "(" << cubicle->row << "," << cubicle->col << ")";
    if (cubicle != head) {
        std::cout << " -> ";
    }
}

void Stack::printReverse() const {
    printReverseHelper(head);
    std::cout << std::endl;
}
Cubicle& Stack::peek(){
    if (isEmpty()) {
        std::cout << "It is empty, cannot be peeked.";
    }
    return *head;
}
bool Stack::isEmpty() const {
    return head == nullptr;
}
