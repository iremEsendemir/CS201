//
//  DVD.h
//  cs201 hw1
//
//  Created by İrem Esendemir on 25.02.2024.
//

#ifndef DVD_h
#define DVD_h
class DVD{
public:
    // Constructors
    DVD(const std::string sNo,const std::string titleOfMovie,const std::string directorOfMovie);
    DVD();
    DVD(const DVD& willBeCopiedDVd);
    
    //setters
    void makeAvailable();
    void makeRented();
    
    //getters
    std::string getSerialNo() const;
    std::string getTitle() const;
    std::string getDirector() const;
    bool getRented() const;
    
private:
    std::string serialNo;
    std::string title;
    std::string director;
    bool rented;
};

#endif /* DVD_h */
