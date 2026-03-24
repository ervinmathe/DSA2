#pragma

#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
#include <algorithm>

using namespace std ;

int firstExercises(); 

void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) ;

void secondExercisesBackTrack(int remaining , vector<pair<int,int>> &moneyNotes , int startIndex , vector<int> &current) ;

void printSecond(vector<int> solution);

bool validSecond(int n , int note) ;
