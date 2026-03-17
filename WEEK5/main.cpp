#include <iostream>
#include "./headers/functions.h"
#include <vector>

using namespace std;

int main() {


    // int n = 5 ;
    // vector<int> arr = {1, 2, 3, 4, 5} ;
    // int m = 3 ;
    // lift(n , arr , m) ;

    vector<pair<int , int>> shows = {{1, 3} , {2, 5} , {2 , 3}, {3 , 5},  {4, 6} , {7, 8}} ;
    int start = 2 ;
    int end = 5 ;
    tvShowsMain(shows , start , end) ;


    return 0 ;
}