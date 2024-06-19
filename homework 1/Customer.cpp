//
//  Customer.cpp
//  cs201 hw1
//
//  Created by İrem Esendemir on 25.02.2024.
//

#include <iostream>
#include <string>
#include "DVD.h"
#include "Customer.h"
using namespace std;

Customer::Customer(const int idOfCustomer, const string nameOfCustomer){
    id = idOfCustomer;
    name = nameOfCustomer;
    rentedList = nullptr;
    rentedNum = 0;
}
Customer::Customer(){
    id = 0;
    name = "";
    rentedList = nullptr;
    rentedNum = 0;
}


Customer::~Customer(){
    delete[] rentedList;
}
int Customer::getId() const{
    return id;
}

Customer::Customer(const Customer& other) {
    id = other.id;
    name = other.name;
    rentedNum = other.rentedNum;
    delete[] rentedList;
    if (rentedNum > 0) {
        rentedList = new DVD[rentedNum];
        for (int i = 0; i < rentedNum; i++) {
            rentedList[i] = other.rentedList[i];
        }
    } else {
        rentedList = nullptr;
    }
}
Customer& Customer::operator=(const Customer& right) {
    if (this != &right) {
            id = right.id;
            name = right.name;
            rentedNum = right.rentedNum;
            delete[] rentedList;
            if (rentedNum > 0) {
                rentedList = new DVD[rentedNum];
                for (int i = 0; i < rentedNum; i++) {
                    rentedList[i] = right.rentedList[i];
                }
            } else {
                rentedList = nullptr;
            }
        }
        return *this;
}

std::string Customer::getName() const{
    return name;
}
DVD* Customer::getRentedList() const{
    return rentedList;
}
int Customer::getRentedNum() const{
    return rentedNum;
}
void Customer::setRentedList(DVD* newRentedList){
    rentedList = newRentedList;
}
void Customer::setRentedNum(int newRentedNum){
    rentedNum = newRentedNum;
}

