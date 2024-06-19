/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#include "Pathway.h"
Pathway::Pathway():ID(0), name(""), proteinList(LinkedList<Protein>()){
    ID = 0;
    name = "";
    proteinList = LinkedList<Protein>();
}

Pathway::Pathway(const int pathwayID,const std::string pathwayName){
    ID = pathwayID;
    name = pathwayName;
    proteinList = LinkedList<Protein>();
}

Pathway::Pathway(const Pathway& willBeCopiedPathway){
    ID = willBeCopiedPathway.ID;
    name = willBeCopiedPathway.name;
    proteinList = willBeCopiedPathway.proteinList;
}

std::string Pathway::getName() const{
    return name;
}

int Pathway::getID() const{
    return ID;
}

LinkedList<Protein>& Pathway::getProteinList(){
    return proteinList;
}

int Pathway::getGeneNum() const{
    int totalGene = 0;
    Node<Protein>* currentProtein= proteinList.getNodeAt(1);
    while(currentProtein != nullptr){
        totalGene += currentProtein->getItem().getGeneList().getLength();
        currentProtein = currentProtein->getNext();
    }
    return totalGene;
}

bool Pathway::operator<(const Pathway& other) const{
    return this->ID<other.ID;
}

bool Pathway::operator>(const Pathway& other) const{
    return this->ID > other.ID;
}

bool Pathway::operator==(const Pathway& other) const{
    return this->ID == other.ID;
}

bool Pathway::operator!=(const Pathway& other) const{
    return this->ID != other.ID;
}
