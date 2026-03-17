#include "../headers/functions.h"
#include <iostream>

using namespace std ;

void lift(int n , vector<int> arr , int m) {
    sort(arr.begin() , arr.end()) ;
    int sum = 0 ;
    for(int i = 0; i < m ; i++) {
        sum += arr[i] ;
    }

    cout << sum << endl ;

}

bool validTVShow(int start ,  int end , pair<int,int> show) {
    if(show.first >= start &&  show.second <= end) {
        return true ;
    }
    else {
        return false ;
    }
}


void tvShows(vector<pair<int , int>> shows , int start , int end , int index , int &count) {

    if(index == shows.size()) {
        return ;
    } else {
        if(validTVShow(start , end , shows[index])) {
            count += 1 ;
            tvShows(shows , shows[index].second , end, index + 1 , count) ;
        } else {
            tvShows(shows , start , end, index + 1 , count) ;
        }
        
    }
    return ;
}

void tvShowsMain(vector<pair<int , int>> shows , int start , int end) {
    int count = 0 ; 
    sort(shows.begin() , shows.end() , [](pair<int,int> a , pair<int,int> b) {
        return a.second < b.second ;
    }) ;
    tvShows(shows , start , end , 0 , count) ;
    cout << count << " musort tudnak megnezni egy tevevel" << endl << endl ;
    count = 0 ; 
    tvShowsN(shows , start , end , count) ;

     
}


void tvShowsN(vector<pair<int , int>> shows , int start , int end , int &count , int index) {
    if(index == shows.size()) {
        return ;
    } else {
        
    }
}

