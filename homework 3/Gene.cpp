/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#include "Gene.h"

Gene::Gene(){
    ID = 0;
    name = "";
}

Gene::Gene(const int geneID,const std::string geneName){
    ID = geneID;
    name = geneName;
}

Gene::Gene(const Gene& willBeCopiedGene){
    ID =willBeCopiedGene.ID;
    name = willBeCopiedGene.name;
}

int Gene::getGeneID() const{
    return ID;
}

std::string Gene::getGeneName() const{
    return name;
}

bool Gene::operator<(const Gene& other) const{
    return ID<other.ID;
}

bool Gene::operator>(const Gene& other) const{
    return ID > other.ID;
}

bool Gene::operator==(const Gene& other) const{
    return ID == other.ID;
}

bool Gene::operator!=(const Gene& other) const{
    return ID != other.ID;
}
