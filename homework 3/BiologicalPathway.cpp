/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */


#include <iostream>
#include <string>
#include "BiologicalPathway.h"

using namespace std;

BiologicalPathway::BiologicalPathway(){
    pathwayList = LinkedList<Pathway>();
}

BiologicalPathway::~BiologicalPathway(){}

void BiologicalPathway::addPathway( const int pathwayId, const string pathwayName ){
    Pathway pathway(pathwayId, pathwayName);
    //check if it exists
    bool exist = pathwayList.isExist(pathway);
    //if it exists, it is not added and the error message is printed
    if (exist) {
        cout << "Cannot add pathway. There is already a pathway with ID " << pathwayId << "." << endl;
        return;
    }
    //if it does not exist it is inserted to the pathway list.
    if(pathwayList.insert(pathway)){
        cout << "Added pathway " << pathwayId << "." << endl;
        return;
    }
    
}
void BiologicalPathway::removePathway( const int pathwayId ){
    Pathway toBeRemoved(pathwayId, "");
    //check if it exists
    bool exist = pathwayList.isExist(toBeRemoved);
    //if it does not exist, it is not removed and the error message is printed
    if (!exist) {
        cout << "Cannot remove pathway. There is no pathway with ID " << pathwayId << "." << endl;
        return;
    }
    //if it exists, it is removed from the pathway list
    if(pathwayList.remove(toBeRemoved)){
        cout << "Removed pathway " << pathwayId << "." << endl;
        return;
    }
}

void BiologicalPathway::printPathways() const{
    //if list is empty
    if(pathwayList.isEmpty()){
        cout << "There are no pathways to show."<<endl;
    }
    else{
        cout<<"Pathways in the system:"<<endl;
        Node<Pathway>* curr = pathwayList.getNodeAt(1);
        while(curr != nullptr){
            cout << "Pathway "<<curr->getItem().getID()<<" : "<<curr->getItem().getName()<<" (" << curr->getItem().getProteinList().getLength() << " Proteins) (" << curr->getItem().getGeneNum() << " Genes)" << endl;
            curr = curr->getNext();
        }
    }
}
void BiologicalPathway::addProtein(const int proteinId, const int pathwayId) {
    Pathway pathway(pathwayId, "");
    Protein protein(proteinId);
    bool isPathwayFound = pathwayList.isExist(pathway);
    //if no pathway exists with this ID
    if (!isPathwayFound) {
        cout << "Cannot add protein. There is no pathway with ID " << pathwayId << "." << endl;
        return;
    }
    //if there is a pathway with this protein
    Node<Pathway>* currPathway = pathwayList.getNodeAt(1);
    while (currPathway != nullptr) {
        Node<Protein>* currentProtein = currPathway->getItem().getProteinList().getNodeAt(1);
        while (currentProtein != nullptr) {
            if (currentProtein->getItem().getID() == proteinId) {
                cout << "Cannot add protein. There is a pathway having a protein with ID " << proteinId << "." << endl;
                return;
            }
            currentProtein = currentProtein->getNext();
        }
        currPathway = currPathway->getNext();
    }
    //protein is inserted
    currPathway = pathwayList.getNodeAt(1);
    while (currPathway != nullptr) {
        if (currPathway->getItem().getID() == pathwayId) {
            Protein toAdd(proteinId);
            currPathway->getItem().getProteinList().insert(toAdd);
            cout << "Added protein " << proteinId << " to pathway " << pathwayId << "." << endl;
            return;
        }
        currPathway = currPathway->getNext();
    }
}

void BiologicalPathway::removeProtein( const int proteinId, const int pathwayId ){
    bool isPathwayFound = false;
    
    Pathway egPathway(pathwayId, "");
    Protein egProtein(proteinId);
    Node<Pathway>* currPathway = pathwayList.getNodeAt(1);
    Node<Pathway>* foundedPathway = nullptr;
    
    //check whether pathway exists
    while(currPathway != nullptr && !isPathwayFound){
        if(currPathway->getItem()==egPathway){
            isPathwayFound = true;
            foundedPathway = currPathway;
            break;
        }
        currPathway = currPathway->getNext();
    }
    //if pathway does not exist
    if(!isPathwayFound){
        cout << "Cannot remove protein. There is no pathway with ID " << pathwayId << "." << endl;
        return;
    }
    
    LinkedList<Protein>& proteinList = foundedPathway->getItem().getProteinList();
    //if pathway has the protein
    if (proteinList.isExist(egProtein)) {
        proteinList.remove(egProtein);
        cout << "Removed protein " << proteinId << " from pathway " << pathwayId << "." << endl;
    } 
    //if the pathway does not have the protein
    else {
        cout << "Cannot remove protein. Pathway " << pathwayId << " does not have a protein with ID " << proteinId << "." << endl;
    }
    
}

void BiologicalPathway::printProteinsInPathway(const int pathwayId) const {
    Pathway toPrint(pathwayId, "");
    //if pathway is empty
    if (!pathwayList.isExist(toPrint)) {
        std::cout << "Cannot print proteins. There is no pathway with ID " << pathwayId << "." << std::endl;
        return;
    }
    
    Node<Pathway>* currentPathway = pathwayList.getNodeAt(1);
    while (currentPathway != nullptr) {
        if (currentPathway->getItem() == toPrint) {
            if (currentPathway->getItem().getProteinList().isEmpty()) {
                std::cout << "There are no proteins to show in pathway " << pathwayId << "." << std::endl;
                return;
            }
            std::cout << "Proteins in pathway " << pathwayId << ":" << std::endl;
            Node<Protein>* currentProtein = currentPathway->getItem().getProteinList().getNodeAt(1);
            while (currentProtein != nullptr) {
                std::cout << "Protein ID : " << currentProtein->getItem().getID() << ", Gene IDs : ";
                if(currentProtein->getItem().getGeneList().isEmpty()){
                    cout << "None" <<endl;
                }
                else{
                    cout << "[";
                    Node<Gene>* currentGene =currentProtein->getItem().getGeneList().getNodeAt(1);
                    for (int i = 1; i < currentProtein->getItem().getGeneList().getLength(); i++) {
                        cout << currentGene->getItem().getGeneID() << ", ";
                        currentGene = currentGene->getNext();
                    }
                    cout << currentGene->getItem().getGeneID() << "]"<<endl;
                }
                currentProtein = currentProtein->getNext();
            }
            return;
        }
        currentPathway = currentPathway->getNext();
    }
}

void BiologicalPathway::addGene( const int geneID, const string geneName, const int proteinId ){
    bool doesProteinExist = false;
    bool doesGeneExist = false;
    Protein* foundProtein = nullptr;
    Gene toAdd(geneID, geneName);
    
    //check protein existence and gene existence and find targeted protein
    Node<Pathway>* currentPathway = pathwayList.getNodeAt(1);
    while(currentPathway != nullptr && (!doesProteinExist || !doesGeneExist)){
        LinkedList<Protein>& proteinList = currentPathway->getItem().getProteinList();
        Node<Protein>* currentProtein = proteinList.getNodeAt(1);
        while (currentProtein != nullptr) {
            //if protein is found
            if (currentProtein->getItem().getID() == proteinId) {
                foundProtein = &(currentProtein->getItem());
                doesProteinExist = true;
            }
            // if gene is found in some protein
            if (currentProtein->getItem().getGeneList().isExist(toAdd)) {
                doesGeneExist = true;
            }
            currentProtein = currentProtein->getNext();
        }
        currentPathway = currentPathway->getNext();
    }
    //if protein does not exist
    if(!doesProteinExist){
        cout << "Cannot add gene. There is no protein with ID "<<proteinId<<"."<<endl;
        return;
    }
    //if gene exists
    if (doesGeneExist) {
       cout << "Cannot add gene. Gene " << geneID << " is already in use." << endl;
       return;
    }

   // gene is inserted to the protein
    if (foundProtein) {
        foundProtein->getGeneList().insert(toAdd);
        cout << "Added gene " << geneID << " to protein " << proteinId << "." << endl;
    }
}
void BiologicalPathway::removeGene( const int geneID, const int proteinId ){
    bool doesProteinExist = false;
    bool doesGeneExist = false;
    Gene toDelete(geneID, "");
    Protein* targetedProtein = nullptr;
    
    //check protein existence and gene existence and find targeted protein
    Node<Pathway>* currentPathway = pathwayList.getNodeAt(1);
    while(currentPathway != nullptr && !doesProteinExist){
        LinkedList<Protein>& proteinList = currentPathway->getItem().getProteinList();
        Node<Protein>* currentProtein = proteinList.getNodeAt(1);
        while (currentProtein != nullptr && !doesProteinExist) {
            //If protein exists
            if (currentProtein->getItem().getID() == proteinId) {
                doesProteinExist = true;
                targetedProtein = &(currentProtein->getItem());
                //If the gene is found in the protein
                if (currentProtein->getItem().getGeneList().isExist(toDelete)) {
                    doesGeneExist = true;
                }
            }
            currentProtein = currentProtein->getNext();
        }
        currentPathway = currentPathway->getNext();
    }
    
    //if protein does not exist
    if(!doesProteinExist){
        cout << "Cannot remove gene. There is no protein with ID "<<proteinId<<"."<<endl;
        return;
    }
    //if gene does not exist
    if(!doesGeneExist){
        cout << "Cannot remove gene. There is no gene "<<geneID<<" encoding protein "<<proteinId << "." << endl;
        return;
    }
    targetedProtein->getGeneList().remove(toDelete);
    cout << "Removed gene "<<geneID<<" from protein "<<proteinId<<"."<<endl;
    
}
void BiologicalPathway::printGenesOfProtein( const int proteinId ) const{
    Node<Pathway>* currentPathway = pathwayList.getNodeAt(1);
    //find the pathway
    while(currentPathway != nullptr){
        Node<Protein>* currentProtein = currentPathway->getItem().getProteinList().getNodeAt(1);
        //find the protein
        while(currentProtein != nullptr){
            if(currentProtein->getItem().getID()==proteinId){
                //if protein does not have any gene
                if(currentProtein->getItem().getGeneList().isEmpty()){
                    cout << "There are no genes to show in protein "<<proteinId<<"."<<endl;
                }
                //protein has some genes
                else{
                    cout <<"Genes in protein "<<proteinId<<":"<<endl;
                    Node<Gene>* currentGene = currentProtein->getItem().getGeneList().getNodeAt(1);
                    while(currentGene != nullptr){
                        cout << "GENE "<<currentGene->getItem().getGeneID()<<" : " << currentGene->getItem().getGeneName()<< endl;
                        currentGene = currentGene->getNext();
                    }
                }
                return;
            }
            currentProtein = currentProtein->getNext();
        }
        currentPathway = currentPathway->getNext();
    }
    cout << "Cannot print genes. There is no protein with ID "<<proteinId<<"."<<endl;
}
