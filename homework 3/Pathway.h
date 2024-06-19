/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#ifndef Pathway_h
#define Pathway_h
#include "iostream"
#include "Protein.h"
#include "LinkedList.h"

class Pathway{
public:
    // Constructors
    Pathway(const int pathwayID,const std::string pathwayName);
    Pathway();
    Pathway(const Pathway& willBeCopiedPathway);
    
    //getters
    std::string getName() const;
    int getID() const;
    LinkedList<Protein>& getProteinList();
    int getGeneNum() const;
    
    //operator overloading
    bool operator<(const Pathway& other) const;
    bool operator>(const Pathway& other) const;
    bool operator==(const Pathway& other) const;
    bool operator!=(const Pathway& other) const;

    
private:
    std::string name;
    int ID;
    LinkedList<Protein> proteinList;
};

#endif /* Pathway_h */
