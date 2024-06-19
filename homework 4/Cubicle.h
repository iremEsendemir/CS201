/*
 NAME: Emine İrem Esendemir
 SECTION: 2
 NUMBER: 22202103
 */

#ifndef Cubicle_h
#define Cubicle_h
#include <iostream>
class Cubicle {
public:
    int row, col;
    bool leftWall, bottomWall, rightWall, topWall, visited;
    bool leftPathVisited, bottomPathVisited, rightPathVisited, topPathVisited;
    Cubicle* next;
    Cubicle(int r = 0, int c = 0, bool lw = false, bool bw = false, bool rw = false, bool tw = false, bool v = false)
        :row(r), col(c),leftWall(lw), bottomWall(bw), rightWall(rw), topWall(tw), visited(v), next(nullptr) {
            
            if(topWall) topPathVisited = true;
            else topPathVisited = false;
            
            if(leftWall) leftPathVisited = true;
            else leftPathVisited = false;
            
            if(rightWall) rightPathVisited = true;
            else leftPathVisited = false;
            
            if(bottomWall) bottomPathVisited = true;
            else bottomPathVisited = false;
            
    }

    void clearPaths(){
        if(!rightWall){
            rightPathVisited = 0;
        }
        
        if(!leftWall){
            leftPathVisited = 0;
        }
        
        if(!topWall){
            topPathVisited = 0;
        }
        
        if(!bottomWall){
            bottomPathVisited = 0;
        }
    }
    
    void showAdjacent(){
        std::cout << "(" << row << "," << col << ")" << " ->";
        int remainingCommaNum = 4-(topWall + bottomWall +leftWall + rightWall);
        std::cout << " ";
        
        if(topWall ==0 ){
            std::cout <<  "(" << row -1 << "," << col << ")";
            remainingCommaNum--;
            if(remainingCommaNum != 0){
                std::cout << ",";
            }
        }
       
        
        if(leftWall ==0 ){
            std::cout <<  "(" << row << "," << col - 1<< ")";
            remainingCommaNum--;
            if(remainingCommaNum != 0){
                std::cout << ",";
            }
        }
        
        
        if(rightWall ==0 ){
            std::cout <<  "(" << row << "," << col + 1 << ")";
            remainingCommaNum--;
            if(remainingCommaNum != 0){
                std::cout << ",";
            }
        }
        
        
        if(bottomWall ==0 ){
            std::cout <<  "(" << row + 1<< "," << col << ")";
        }
    }
};

#endif /* Cubicle_h */
