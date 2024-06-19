#include <iostream>
#include <string>
#include "DVD.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;

#include "DVDStoreManagementSystem.h"

DVDStoreManagementSystem::DVDStoreManagementSystem(){
    dvdList = nullptr;
    customerList = nullptr;
    transactionList = nullptr;
    dvdNum = 0;
    customerNum = 0;
    transactionNum = 0;
}

DVDStoreManagementSystem::~DVDStoreManagementSystem(){
    delete[] dvdList;
    delete[] customerList;
    delete[] transactionList;
}

void DVDStoreManagementSystem::addDVD( const string serialNo, const string title, const string director ){
    //adding first dvd
    if (dvdNum == 0) {
        dvdList = new DVD[1];
        dvdList[0] = DVD(serialNo, title, director);
        dvdNum = 1;
        cout << "DVD with serial number " << serialNo << " successfully added."<< endl;
        return;
    }
    
    //checks if it already exists
    for (int i = 0; i < dvdNum; ++i) {
        if (dvdList[i].getSerialNo() == serialNo) {
            cout << "Cannot add DVD. DVD with serial number " << serialNo << " already exists."<< endl;
            return;
        }
    }
    
    // adding it to the array
    DVD* temp = new DVD[dvdNum + 1]; // Create a temporary array to hold DVDs
    for (int i = 0; i < dvdNum; i++) {
        temp[i] = dvdList[i]; // Copy existing DVDs to temporary array
    }
    temp[dvdNum] = DVD(serialNo, title, director); // Add the new DVD
    delete[] dvdList; // Deallocate memory for old dvdList
    dvdList = temp; // Update dvdList to point to the new array
    dvdNum++;
    cout << "DVD with serial number " << serialNo << " successfully added."<< endl;
}

void DVDStoreManagementSystem::removeDVD( const string serialNo ){
    //finding the index
    int pos = -1;
    for (int i = 0; i < dvdNum && pos == -1; i++) {
        if(dvdList[i].getSerialNo()==serialNo){
            pos = i;
            if(dvdList[i].getRented()==true){
                //checking if it is rented
                cout << "Cannot remove DVD. DVD with serial number " << serialNo << " is currently rented by a customer."<< endl;
                return;
            }
        }
    }
    //if it does not exist
    if(pos == -1){
        cout << "Cannot remove DVD. DVD with serial number " << serialNo << " not found."<< endl;
        return;
    }
    
    DVD* temp = new DVD[dvdNum - 1];
    // Copy DVDs before the one to be removed
    for (int i = 0; i < pos; i++) {
        temp[i] = dvdList[i];
    }
    // Copy DVDs after the one to be removed
    for (int i = pos; i < dvdNum - 1; i++) {
        temp[i] = dvdList[i+1];
    }
    delete[] dvdList;
    dvdList = temp;
    dvdNum--;
    cout << "DVD with serial number " << serialNo << " successfully removed." << endl;
}

void DVDStoreManagementSystem::addCustomer( const int customerID, const string name ){
    //adding first customer
    if (customerNum == 0) {
        customerList = new Customer[1];
        customerList[0] = Customer(customerID, name);
        customerNum = 1;
        cout << "Customer with ID " << customerID << " successfully added."<< endl;
        return;
    }
    //checking if it already exists
    for (int i = 0; i < customerNum; ++i) {
        if (customerList[i].getId() == customerID) {
            cout << "Cannot add customer. Customer with ID " << customerID << " already exists."<< endl;
            return;
        }
    }
    //adding the new one
    Customer* temp = new Customer[customerNum + 1]; // Create a temporary array to hold customers
    for (int i = 0; i < customerNum; i++) {
        temp[i] = customerList[i]; // Copy existing customers to temporary array
    }
    temp[customerNum] = Customer(customerID, name); // Add the new one
    delete[] customerList;
    customerList = temp;
    customerNum++;
    cout << "Customer with ID " << customerID << " successfully added."<< endl;
}

void DVDStoreManagementSystem::removeCustomer( const int customerID ){
    //finding the index, pos remains -1 if it does not exist
    int pos = -1;
    for (int i = 0; i < customerNum && pos == -1; i++) {
        if(customerList[i].getId()==customerID){
            pos = i;
            // if the customer has rented DVDs
            if(customerList[i].getRentedNum() != 0){
                cout << "Cannot remove customer. Customer with ID " << customerID << " has rented DVDs."<< endl;
                return;
            }
        }
    }
    
    if(pos == -1){
        cout << "Cannot remove customer. Customer with ID " << customerID << " not found."<< endl;
        return;
    }
    
    Customer* temp = new Customer[customerNum - 1];
    // Copy customers before the one to be removed
    for (int i = 0; i < pos; i++) {
        temp[i] = customerList[i];
    }
    // Copy customers after the one to be removed
    for (int i = pos; i < customerNum - 1; i++) {
        temp[i] = customerList[i+1];
    }
    delete[] customerList;
    customerList = temp;
    customerNum--;
    cout << "Customer with ID " << customerID << " successfully removed." << endl;
}

void DVDStoreManagementSystem::rentDVD( const int customerID, const string serialNo ){
    bool isDVDAvailable= false;
    int DVDindex = -1, customerIndex = -1;
    //DVD existence check:
    for(int i = 0; i < dvdNum; i++){
        if(dvdList[i].getSerialNo() == serialNo && serialNo == dvdList[i].getSerialNo()){
            DVDindex = i;
            if (dvdList[i].getRented()==false) {
                isDVDAvailable = true;
            }
            break;
        }
    }
    
    //customer existence check
    for(int i = 0; i < customerNum; i++){
        if(customerList[i].getId() == customerID){
            customerIndex = i;
            break;
        }
    }
    
    //no DVD and no customer
    if(DVDindex == -1 && customerIndex == -1){
        cout << "Cannot rent DVD. Customer with ID "<< customerID << " and DVD with serial number "<< serialNo<<" not found." << endl;
        return;
    }
    
    //no customer
    else if (customerIndex == -1){
        cout << "Cannot rent DVD. Customer with ID " << customerID <<" not found." << endl;
        return;
    }
    
    //no dvd
    else if (DVDindex == -1){
        cout << "Cannot rent DVD. DVD with serial number " << serialNo <<" not found." << endl;
        return;
    }
    
    //dvd not available
    else if (!isDVDAvailable){
        cout << "Cannot rent DVD. DVD with serial number " << serialNo <<" is not available."<<endl;
        return;
    }
    //renting part
    dvdList[DVDindex].makeRented();
    //if it is the first dvd of the customer
    if(customerList[customerIndex].getRentedNum()==0){
        DVD* newCustomerDVDList = new DVD[1];
        newCustomerDVDList[0] = DVD(dvdList[DVDindex]);
        customerList[customerIndex].setRentedList(newCustomerDVDList);
        customerList[customerIndex].setRentedNum(1);
    }
    
    else{
        int oldRentedNum =customerList[customerIndex].getRentedNum();
        DVD* temp = new DVD[oldRentedNum + 1];
        for (int i = 0; i < oldRentedNum; i++) {
            temp[i] = customerList[customerIndex].getRentedList()[i];
        }
        temp[oldRentedNum] = DVD(dvdList[DVDindex]);
        delete[] customerList[customerIndex].getRentedList();
        customerList[customerIndex].setRentedList(temp);
        customerList[customerIndex].setRentedNum(oldRentedNum + 1);
    }
    
    //transaction part
    if(transactionNum == 0){
        Transaction* tempTransaction = new Transaction[1];
        tempTransaction[0] = Transaction(true, serialNo, customerID);
        transactionList = tempTransaction;
    }
    else{
        Transaction* tempTransaction = new Transaction[transactionNum+1];
        for (int i = 0; i < transactionNum; i++) {
            tempTransaction[i] = transactionList[i];
        }
        tempTransaction[transactionNum] = Transaction(true, serialNo, customerID);
        delete[] transactionList;
        transactionList = tempTransaction;
    }
    transactionNum++;
    cout << "DVD with serial number " << serialNo<<" successfully rented by customer with ID " << customerID << "." << endl;
}
void DVDStoreManagementSystem::returnDVD( const int customerID, const string serialNo ){
    int DVDindex = -1, customerIndex = -1, dvdIndexOfCustomer = -1;
    //customer existence check
    for(int i = 0; i < customerNum; i++){
        if(customerList[i].getId() == customerID){
            customerIndex = i;
            break;
        }
    }
    //DVD existence check:
    for(int i = 0; i < dvdNum; i++){
        if(dvdList[i].getSerialNo() == serialNo ){
            DVDindex = i;
            break;
        }
    }
    //owner-match check
    if(customerIndex != -1 && DVDindex != -1){
        for(int i = 0; i < customerList[customerIndex].getRentedNum(); i++){
            if(customerList[customerIndex].getRentedList()[i].getSerialNo() == serialNo){
                dvdIndexOfCustomer = i;
                break;
            }
        }
    }
    if (DVDindex == -1 && customerIndex == -1) {
        cout << "Cannot return DVD. Customer with ID " <<customerID<< " and DVD with serial number " <<serialNo<< " not found."<<endl;
        return;
    }
    else if(customerIndex == -1){
        cout << "Cannot return DVD. Customer with ID " <<customerID<< " not found."<<endl;
        return;
    }
    else if(DVDindex == -1){
        cout << "Cannot return DVD. DVD with serial number " <<serialNo<< " not found."<<endl;
        return;
    }
    else if (dvdIndexOfCustomer == -1){
        cout << "Cannot return DVD. DVD with serial number "<<serialNo<<" not rented by customer with ID " << customerID << "."<<endl;
        return;
    }
    
    //returning the DVD
    /*int oldRentedNum =customerList[customerIndex].getRentedNum();
    DVD* temp = new DVD[oldRentedNum - 1];
    // Copy DVDs before the one to be removed
    for (int i = 0; i < dvdIndexOfCustomer; i++) {
        temp[i] = customerList[customerIndex].getRentedList()[i];
    }
    // Copy DVDs after the one to be removed
    for (int i = oldRentedNum; i < oldRentedNum - 1; i++) {
        temp[i] = customerList[customerIndex].getRentedList()[i+1];
    }
    delete[] customerList[customerIndex].getRentedList();
    customerList[customerIndex].setRentedList(temp);
    customerList[customerIndex].setRentedNum(oldRentedNum - 1);
    dvdList[DVDindex].makeAvailable();*/
    //returning the DVD
    int oldRentedNum = customerList[customerIndex].getRentedNum();
    DVD* temp = new DVD[oldRentedNum - 1];
    // Copy DVDs before the one to be removed
    for (int i = 0; i < dvdIndexOfCustomer; i++) {
        temp[i] = customerList[customerIndex].getRentedList()[i];
    }
    // Copy DVDs after the one to be removed
    for (int i = dvdIndexOfCustomer + 1; i < oldRentedNum; i++) {
        temp[i - 1] = customerList[customerIndex].getRentedList()[i];
    }
    delete[] customerList[customerIndex].getRentedList();
    customerList[customerIndex].setRentedList(temp);
    customerList[customerIndex].setRentedNum(oldRentedNum - 1);
    dvdList[DVDindex].makeAvailable();
    
    //transaction part
    Transaction* tempTransaction = new Transaction[transactionNum+1];
    for (int i = 0; i < transactionNum; i++) {
        tempTransaction[i] = transactionList[i];
    }
    tempTransaction[transactionNum] = Transaction(false, serialNo, customerID);
    delete[] transactionList;
    transactionList = tempTransaction;
    transactionNum++;
    cout << "DVD with serial number "<<serialNo<<" successfully returned by customer with ID "<<customerID<<"." << endl;
}

void DVDStoreManagementSystem::showAllDVDs() const{
    cout << "DVDs in the system:"<<endl;
    if(dvdNum == 0){
        cout << "None" << endl;
        return;
    }
    for(int i = 0; i < dvdNum; i++){
        cout << "DVD: " << dvdList[i].getSerialNo() << ", Title: " << dvdList[i].getTitle();
        cout << ", Director: " << dvdList[i].getDirector();
        if (dvdList[i].getRented()==true) {
            cout << ", Rented" << endl;
        } else {
            cout << ", Available" << endl;
        }
    }
}
void DVDStoreManagementSystem::showAllCustomers() const{
    cout << "Customers in the system:"<<endl;
    if(customerNum == 0){
        cout << "None" << endl;
        return;
    }
    for(int i = 0; i < customerNum; ++i){
        cout << "Customer: " << customerList[i].getId() << ", Name: " << customerList[i].getName();
        cout << ", DVDs Rented: " << customerList[i].getRentedNum() << endl;
    }
}
void DVDStoreManagementSystem::showDVD( const string serialNo ) const{
    for(int i = 0; i < dvdNum; i++){
        if(dvdList[i].getSerialNo() == serialNo){
            cout << "DVD: " << dvdList[i].getSerialNo() << ", Title: " << dvdList[i].getTitle();
            cout << ", Director: " << dvdList[i].getDirector();
            if (dvdList[i].getRented()==true) {
                cout << ", Rented" << endl;
            } else {
                cout << ", Available" << endl;
            }
            return;
        }
    }
    cout << "DVD with serial number " << serialNo << " not found."<< endl;
}
void DVDStoreManagementSystem::showCustomer( const int customerID ) const{
    for(int i = 0; i < customerNum; i++){
        if(customerList[i].getId() == customerID){
            cout << "Customer: " << customerList[i].getId() << ", Name: " << customerList[i].getName();
            cout << ", DVDs Rented: " << customerList[i].getRentedNum() << endl;
            return;
        }
    }
    cout << "Customer with ID " << customerID << " not found."<< endl;
}
void DVDStoreManagementSystem::showTransactionHistory() const{
    cout << "Transactions in the system:"<<endl;
    if(transactionNum == 0){
        cout << "None"<<endl;
    }
    for (int i = 0; i < transactionNum; i++) {
        cout << transactionList[i].toString();
    }
}
