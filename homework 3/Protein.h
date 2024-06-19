/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */
#ifndef Protein_h
#define Protein_h
#include "iostream"
#include "LinkedList.h"
#include "Gene.h"

class Protein{
public:
    // Constructors
    Protein(const int proteinID);
    Protein();
    Protein(const Protein& willBeCopiedProtein);

    //getters
    int getID() const;
    LinkedList<Gene>& getGeneList();
    
    //operator overloading
    bool operator<(const Protein& other) const;
    bool operator>(const Protein& other) const;
    bool operator==(const Protein& other) const;
    bool operator!=(const Protein& other) const;

private:
    int ID;
    LinkedList<Gene> geneList;
};

#endif /* Protein_h */
