#include "../headers/functions.h"

int firstExercises() {
    int n , m;
    vector<int> kids , candies ;
    ifstream file ;
    file.open("input1.txt") ;

    file >> n ;
    for(int i = 0 ; i < n ; i++) {
        int temp ;
        file >> temp ;
        kids.push_back(temp) ;
    }

    file >> m ;
    for(int i = 0 ; i < n ; i++) {
        int temp ;
        file >> temp ;
        candies.push_back(temp) ;
    }

    int count = 0 ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(kids[i] == candies[j]) {
                count++ ;
                candies.erase(candies.begin() + j) ;
                break ;
            }
        }
    }

    return count;

}




void secondExercises() {

}

void printSecond() {

}

bool validSecond() {
    return true ;
}