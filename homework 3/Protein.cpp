/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#include "Protein.h"

Protein::Protein(){
    ID = 0;
    geneList = LinkedList<Gene>();
}
Protein::Protein(const int proteinID){
    ID = proteinID;
    geneList = LinkedList<Gene>();
}

Protein::Protein(const Protein& willBeCopiedProtein){
    ID = willBeCopiedProtein.ID;
    geneList = willBeCopiedProtein.geneList;
}

//getters
int Protein::getID() const{
    return ID;
}
LinkedList<Gene>& Protein::getGeneList() {
    return geneList;
}

//operator overloading
bool Protein::operator<(const Protein& other) const{
    return this->ID<other.ID;
}
bool Protein::operator>(const Protein& other) const{
    return this->ID > other.ID;
}
bool Protein::operator==(const Protein& other) const{
    return this->ID == other.ID;
}
bool Protein::operator!=(const Protein& other) const{
    return this->ID != other.ID;
}
