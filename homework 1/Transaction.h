//
//  Transaction.h
//  cs201 hw1
//
//  Created by İrem Esendemir on 27.02.2024.
//

#ifndef Transaction_h
#define Transaction_h

class Transaction{
public:
    //Constructors
    Transaction();
    Transaction(const bool isRentalBoolean,const std::string serialNumber,const int customerIdNumber);
    
    //converting the informations to string
    std::string toString();
    
private:
    bool isRental;
    std::string serialNo;
    int customerId;
};
#endif /* Transaction_h */
