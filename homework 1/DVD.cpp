//
//  DVD.cpp
//  cs201 hw1
//
//  Created by İrem Esendemir on 25.02.2024.
//
#include <iostream>
#include <string>
#include "DVD.h"
using namespace std;

DVD::DVD(string sNo, string titleOfMovie, string directorOfMovie){
    serialNo = sNo;
    title = titleOfMovie;
    director = directorOfMovie;
    rented = false;
}
DVD::DVD(){
    serialNo = "";
    title = "";
    director = "";
    rented = false;
}
DVD::DVD(const DVD& willBeCopied){
    serialNo = willBeCopied.serialNo;
    title = willBeCopied.title;
    director = willBeCopied.director;
    rented = true;
}
void DVD::makeRented(){
    rented = true;
}
void DVD::makeAvailable(){
    rented = false;
}
string DVD::getSerialNo() const{
    return serialNo;
}
string DVD::getTitle() const{
    return title;
}
bool DVD::getRented() const{
    return rented;
}
string DVD::getDirector() const{
    return director;
}


