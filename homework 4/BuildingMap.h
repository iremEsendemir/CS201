/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#ifndef BuildingMap_h
#define BuildingMap_h
#include "Stack.h"
class BuildingMap {
public:
    BuildingMap(const std::string buildingMapFile);
    ~BuildingMap();
    void displayAllCubicles() const;
    void displayAdjacentCubicles(const int row, const int col) const;
    void displayBuildingMap() const;
    void findPaths(const int startRow, const int startCol, const int endRow, const int endCol);
    void findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol);
private:
    int rows, cols;
    Cubicle** allCubicles;
    void displayPaths(const int startRow, const int startCol, const int endRow, const int endCol);
};
    
#endif /* BuildingMap_h */
