//
//  Customer.h
//  cs201 hw1
//
//  Created by İrem Esendemir on 25.02.2024.
//

#ifndef Customer_h
#define Customer_h
class Customer{
public:
    //Constructors
    Customer(const int idOfCustomer, const std::string nameOfCustomer);
    Customer();
    Customer(const Customer& other);
    
    //Destructors
    ~Customer();
    
    //overloading =
    Customer& operator=( const Customer& );
    
    //getters
    std::string getName() const;
    DVD* getRentedList() const;
    int getId() const;
    int getRentedNum() const;
    
    //setters
    void setRentedList(DVD* newRentedList);
    void setRentedNum(const int newRentedNum);
    
private:
    int id;
    std::string name;
    DVD* rentedList;
    int rentedNum;
};

#endif /* Customer_h */
