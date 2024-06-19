//
//  DVDStoreManagementSystem.h
//  cs201 hw1
//
//  Created by İrem Esendemir on 27.02.2024.
//


#ifndef DVDSTOREMANAGEMENTSYSTEM_H
#define DVDSTOREMANAGEMENTSYSTEM_H
#include "DVD.h"
#include "Customer.h"
#include "Transaction.h"


class DVDStoreManagementSystem {
public:
DVDStoreManagementSystem();
~DVDStoreManagementSystem();
    void addDVD( const string serialNo, const string title, const string director );
    void removeDVD( const string serialNo );
    void addCustomer( const int customerID, const string name );
    void removeCustomer( const int customerID );
    void rentDVD( const int customerID, const string serialNo );
    void returnDVD( const int customerID, const string serialNo );
    void showAllDVDs() const;
    void showAllCustomers() const;
    void showDVD( const string serialNo ) const;
    void showCustomer( const int customerID ) const;
    void showTransactionHistory() const;
private:
    DVD* dvdList;
    Customer* customerList;
    Transaction* transactionList;
    int dvdNum;
    int customerNum;
    int transactionNum;
};

#endif 
