#pragma once

#include <vector>
#include <algorithm>


using namespace std ;

void lift(int n , vector<int> arr , int m) ;


void tvShows(vector<pair<int , int>> shows , int start , int end , int index , int &count) ;

void tvShowsMain(vector<pair<int , int>> shows , int start , int end) ;

bool validTVShow(int start ,  int end , pair<int,int> show) ;