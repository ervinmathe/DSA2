#include "../headers/functions.h"



void greedyVsBacktrack1(int osszeg , vector<pair<int,int>> cimletek) {
    
    vector<int> felhasznalt(cimletek.size(), 0);
    int hatra = osszeg;
    
    for (int i = 0; i < cimletek.size() && hatra > 0; i++) {
        int ertek = cimletek[i].first;
        int darab = cimletek[i].second;
        
        int maxFelhasznalhato = min(hatra / ertek, darab);
        
        felhasznalt[i] = maxFelhasznalhato;
        hatra -= maxFelhasznalhato * ertek;
    }
    
    if (hatra != 0) {
        return ;
    }
    
    for(int element : felhasznalt) {
        cout << element << ' ' ;
    }
}

bool compare(pair<int , int> a , pair<int , int> b) {
    return a.second > b.second ;
}

void greedyVsBacktrack2(int n , int k , vector<pair<int , int>> items) {
    sort(items.begin() , items.end() , compare) ;

    vector<int> itemIndexes ;

    int ertek = 0 ;
    int suly = k ;

    for(int i = 0 ; i < n ; i++) {
        if(suly - items[i].first >= 0) {
            ertek += items[i].second ;
            itemIndexes.push_back(i) ;
        } else {
            continue ;
        }
    }


    for(int i : itemIndexes) {
        cout << i << ' ' ;
    }
}





