/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#ifndef BiologicalPathway_h
#define BiologicalPathway_h
#include <iostream>
#include <string>
#include "BiologicalPathway.h"
#include "Gene.h"
#include "Protein.h"
#include "Pathway.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;


class BiologicalPathway {
public:
    BiologicalPathway();
    ~BiologicalPathway();
    void addPathway( const int pathwayId, const string pathwayName );
    void removePathway( const int pathwayId );
    void printPathways() const;
    void addProtein( const int proteinId, const int pathwayId );
    void removeProtein( const int proteinId, const int pathwayId );
    void printProteinsInPathway( const int pathwayId ) const;
    void addGene( const int geneID, const string geneName, const int proteinId );
    void removeGene( const int geneID, const int proteinId );
    void printGenesOfProtein( const int proteinId ) const;
private:
    LinkedList<Pathway> pathwayList;
};


#endif /* BiologicalPathway_h */
