#include <iostream>
#include <fstream>
#include "./headers/functions.h"
#include <chrono>

using namespace std;
using namespace std::chrono ;


int main() {

    /*ifstream file ;
    file.open("input.txt") ;

    int osszeg ; 
    file >> osszeg ;
    vector<pair<int,int>> cimletek ;
    pair<int,int> a ;
    while(file >> a.first >> a.second) {
        cimletek.push_back(a) ;
    }

    file.close() ;



    auto start = high_resolution_clock::now();

    greedyVsBacktrack1(osszeg , cimletek) ;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;*/


    ifstream file ;
    file.open("input2.txt") ;

    int n , k ;
    file >> n >> k ;
    vector<pair<int , int>> items ;
    pair<int , int> item ;
    for(int i = 0 ; i < n ; i++) {
        file >> item.first >> item.second ;
        items.push_back(item) ;
    }

    file.close() ;

    
    return 0 ;
}