#pragma

#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
#include <algorithm>

using namespace std ;

int firstExercises(); 

int findCandyIndex(vector<int> &candies , int j , int m , int need) ;

int countMatches(vector<int> &kids , vector<int> &candies , int i , int n , int m) ;

void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) ;

void secondExercisesBackTrack(int remaining , vector<pair<int,int>> &moneyNotes , int startIndex , vector<int> &current) ;

void printSecond(vector<int> solution);

bool validSecond(int n , int note) ;
