/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#ifndef Gene_h
#define Gene_h
#include "iostream"

class Gene{
public:
    // Constructors
    Gene(const int geneID,const std::string geneName);
    Gene();
    Gene(const Gene& willBeCopiedGene);
    
    //getters
    int getGeneID() const;
    std::string getGeneName() const;
    
    //operator overloading
    bool operator<(const Gene& other) const;
    bool operator>(const Gene& other) const;
    bool operator==(const Gene& other) const;
    bool operator!=(const Gene& other) const;
    
private:
    int ID;
    std::string name;
};

#endif /* Gene_h */
