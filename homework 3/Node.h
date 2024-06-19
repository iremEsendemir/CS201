/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */
#ifndef Node_h
#define Node_h
#include <iostream>
#include <string>

template <typename ItemType>
class Node {
private:
    ItemType item;  // A data item
    Node<ItemType>* next;  // Pointer to next node

public:
    Node() : next(nullptr) {}

    Node(const ItemType& anItem) : item(anItem), next(nullptr) {}

    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) {}

    ItemType& getItem() {
        return item;
    }

    const ItemType& getItem() const {
        return item;
    }

    void setItem(const ItemType& anItem) {
        item = anItem;
    }

    Node<ItemType>* getNext() const {
        return next;
    }

    void setNext(Node<ItemType>* nextNodePtr) {
        next = nextNodePtr;
    }
};

#endif /* Node_h */
