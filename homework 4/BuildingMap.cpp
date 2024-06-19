/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#include "BuildingMap.h"
#include <fstream>
BuildingMap::BuildingMap(const std::string buildingMapFile){
    //read the txt files and save the data
    std::ifstream input;
    input.open(buildingMapFile);
    input >> rows;
    input >> cols;
    std::cout << rows << " rows and "<<cols<<" columns have been read."<<std::endl;
    
    int** takenNumbers = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            takenNumbers[i] = new int[cols];
            std::string line;
            input >> line;
            for (int j = 0; j < cols; ++j) {
                takenNumbers[i][j] = line[j] - '0';  // convert char to int
            }
        }
    input.close();
    
   
    // initialize the cubicle array
        allCubicles = new Cubicle*[rows];
        for (int i = 0; i < rows; ++i) {
            allCubicles[i] = new Cubicle[cols];
        }

        // set the cubicle positions and walls
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                allCubicles[i][j].row = i;
                allCubicles[i][j].col = j;

                int value = takenNumbers[i][j];
                allCubicles[i][j].leftWall = value == 1 || value == 3;
                allCubicles[i][j].bottomWall = value == 2 || value == 3;
                allCubicles[i][j].topWall = (i == 0) || (i > 0 && (takenNumbers[i-1][j] == 2 || takenNumbers[i-1][j] == 3));
                allCubicles[i][j].rightWall = (j == cols-1) || (j < cols-1 && (takenNumbers[i][j+1] == 1 || takenNumbers[i][j+1] == 3));
            }
        }
    
    for(int i = 0; i < rows; i++){
        delete[] takenNumbers[i];
    }
    delete [] takenNumbers;
    
}
BuildingMap::~BuildingMap(){
    for(int i = 0; i < rows; i++){
        delete[] allCubicles[i];
    }
    delete [] allCubicles;
}
void BuildingMap::displayAllCubicles() const{
    std::cout << "The cubicles in the building are:"<<std::endl;
    for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "(" << i << "," << j << ")";
                if (j < cols - 1) {
                    std::cout << ",";
                }
            }
        
            std::cout << std::endl;
        
    }
}
void BuildingMap::displayAdjacentCubicles(const int row, const int col) const{
    std::cout << "The cubicles adjacent to (" << row << "," << col << ") are:" << std::endl;
    allCubicles[row][col].showAdjacent();
    std::cout << std::endl;
}


void BuildingMap::displayBuildingMap() const{
    std::cout << "The building map is as follows:"<< std::endl;
    for(int row = 0; row < rows ; row++){
        for(int col = 0; col < cols; col++){
            allCubicles[row][col].showAdjacent();
            std::cout << std::endl;
        }
    }
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol){
    std::cout << "Paths from (" << startRow << "," << startCol << ") to (" << endRow << "," << endCol << ") are:" << std::endl;
    displayPaths(startRow, startCol, endRow,endCol);
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol){
    int prevTW = allCubicles[avoidRow][avoidCol].topWall;
    int prevLW = allCubicles[avoidRow][avoidCol].leftWall;
    int prevRW = allCubicles[avoidRow][avoidCol].rightWall;
    int prevBW = allCubicles[avoidRow][avoidCol].bottomWall;
    
    allCubicles[avoidRow][avoidCol].topWall = 1;
    allCubicles[avoidRow][avoidCol].leftWall = 1;
    allCubicles[avoidRow][avoidCol].rightWall = 1;
    allCubicles[avoidRow][avoidCol].bottomWall = 1;
    std::cout << "Paths from (" << startRow << "," << startCol << ") to (" << endRow << "," << endCol << ") avoiding ("<< avoidRow <<"," << avoidCol <<") are:" << std::endl;

    BuildingMap::displayPaths(startRow,startCol, endRow, endCol);
    
    allCubicles[avoidRow][avoidCol].topWall = prevTW;
    allCubicles[avoidRow][avoidCol].leftWall = prevLW;
    allCubicles[avoidRow][avoidCol].rightWall = prevRW;
    allCubicles[avoidRow][avoidCol].bottomWall = prevBW;

    
}

void BuildingMap::displayPaths(const int startRow, const int startCol, const int endRow, const int endCol){
    int count = 0;
    Stack stack;
    Cubicle* startCubicle = &allCubicles[startRow][startCol];
    startCubicle->visited = true;
    stack.push(startCubicle);
    
    while (!stack.isEmpty()) {
        Cubicle* current = &(stack.peek());
        if (current->row == endRow && current->col == endCol) {
            count++;
            stack.printReverse();
            stack.pop();
            current->visited = false;
            current->clearPaths();
            continue;
        }
        bool pushed = false;
        //move to the top cubicle
        if (!(current->topWall) && !((allCubicles[current->row - 1][current->col]).visited) && !(current->topPathVisited)) {
            Cubicle* nextCubicle = &allCubicles[current->row - 1][current->col];
            nextCubicle->visited = 1;
            current->topPathVisited = 1;
            stack.push(nextCubicle);
            pushed = 1;
        }
        //move to the left cubicle
        else if (!pushed && !current->leftWall && !((allCubicles[current->row][current->col - 1]).visited) && !(current->leftPathVisited)) {
            Cubicle* nextCubicle = &allCubicles[current->row][current->col - 1];
            nextCubicle->visited = 1;
            current->leftPathVisited = 1;
            stack.push(nextCubicle);
            pushed = 1;
        }
        //move to the right cubicle
        else if (!pushed && !current->rightWall && !((allCubicles[current->row][current->col + 1]).visited)&& !(current->rightPathVisited)) {
            Cubicle* nextCubicle = &allCubicles[current->row][current->col + 1];
            nextCubicle->visited = 1;
            current->rightPathVisited = 1;
            stack.push(nextCubicle);
            pushed = 1;
        }
        //move to the bottom cubicle
        else if (!pushed && !current->bottomWall && !((allCubicles[current->row + 1][current->col]).visited)&& !(current->bottomPathVisited)){
            Cubicle* nextCubicle = &allCubicles[current->row + 1][current->col];
            nextCubicle->visited = 1;
            current->bottomPathVisited = 1;
            stack.push(nextCubicle);
            pushed = 1;
        }
        else if (!pushed) {
            stack.pop();
            current->visited = false;
            if(stack.isEmpty()){
                break;
            }
            current->clearPaths();
        }
    }
    // reset status
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            allCubicles[i][j].visited = false;
            allCubicles[i][j].clearPaths();
        }
    }
    if(count == 0){
        std::cout << "None"<<std::endl;
    }
}
