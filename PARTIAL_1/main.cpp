#include "./headers/functions.h"
#include <iostream>


using namespace std;

int main() {

    ///First exercises
    ///cout << firstExercises() ;
    int n = 786 ;
    vector<pair<int,int>> note = {
        pair<int , int>(500 , 1),
        pair<int , int>(200 , 2),
        pair<int , int>(100 , 1),
        pair<int , int>(50 , 3),
        pair<int , int>(20 , 2),
        pair<int , int>(10 , 5),
        pair<int , int>(5 , 2),
        pair<int , int>(1 , 10)

    } ;
    secondExercises(n , note) ;
    return 0 ;
}