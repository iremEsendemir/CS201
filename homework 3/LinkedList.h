/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */
#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
#include "Node.h"

template<typename ItemType>
class LinkedList {
private:
    Node<ItemType>* headPtr;  // Points to first item in the chain
    int itemCount;  // Number of items in the chain

public:
    LinkedList() : headPtr(nullptr), itemCount(0) {}

    //LinkedList(const LinkedList<ItemType>& aList) : headPtr(aList.headPtr), itemCount(aList.itemCount) {}
    
    ~LinkedList() {
        Node<ItemType>* current = headPtr;
        while (current != nullptr) {
            Node<ItemType>* next = current->getNext();
            delete current;
            current = next;
        }
        headPtr = nullptr;
        itemCount = 0;

    }

    bool isEmpty() const {
        return itemCount == 0;
    }

    int getLength() const {
        return itemCount;
    }

    bool insert(const ItemType& newEntry) {
        Node<ItemType>* newNode = new Node<ItemType>(newEntry);
        if (headPtr == nullptr) {
            headPtr = newNode;
        } else {
            Node<ItemType>* current = headPtr;
            Node<ItemType>* prev = nullptr;
            while (current != nullptr && current->getItem() < newEntry) {
                prev = current;
                current = current->getNext();
            }
            if (prev == nullptr) {
                newNode->setNext(headPtr);
                headPtr = newNode;
            } else {
                newNode->setNext(current);
                prev->setNext(newNode);
            }
        }
        itemCount++;
        return true;
    }

   
    
    bool remove(const ItemType& toBeRemoved) {
           Node<ItemType>* current = headPtr;
           Node<ItemType>* prev = nullptr;
           while (current != nullptr) {
               if (current->getItem() == toBeRemoved) {
                   if (prev == nullptr) {
                       // Removing the head node
                       headPtr = current->getNext();
                   } else {
                       // Removing a middle or last node
                       prev->setNext(current->getNext());
                   }
                   delete current;
                   itemCount--;
                   return true;
               }
               prev = current;
               current = current->getNext();
           }
           return false;
       }

    void clear() {
        while (!isEmpty()) {
            remove(1);
        }
    }

   
    Node<ItemType>* getNodeAt(int position) const {
        if (itemCount == 0 || position < 1 || position > itemCount)
            return nullptr;
        Node<ItemType>* curPtr = headPtr;
        for (int i = 1; i < position; i++) {
            curPtr = curPtr->getNext();
        }
        return curPtr;
    }
    
    Node<ItemType>* getHeadPtr() const{
        return headPtr;
    }
    
    bool isExist(const ItemType& item) const {
        Node<ItemType>* current = headPtr;
        while (current != nullptr) {
            if (current->getItem() == item) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }
};

#endif /* LinkedList_h */
