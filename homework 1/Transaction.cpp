//
//  Transaction.cpp
//  cs201 hw1
//
//  Created by İrem Esendemir on 27.02.2024.
//

#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(){
    isRental = false;
    serialNo = "";
    customerId = 0;
    
}
Transaction::Transaction(const bool isRentalBoolean, const std::string serialNumber, const int customerIdNumber){
    isRental = isRentalBoolean;
    serialNo = serialNumber;
    customerId = customerIdNumber;
}

std::string Transaction::toString(){
    string str= "";
    str += "Transaction: ";
    if (isRental) {
        str += "Rental";
    } else {
        str += "Return";
    }
    str = str + ", Customer: " + std::to_string(customerId) + ", DVD: " + serialNo + "\n";
    return str;
}
