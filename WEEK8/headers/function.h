#pragma
#include <vector>
#include <iostream>

using namespace std;

void melysegiMenet(vector<vector<int>> &G , int u , vector<int> &szin , vector<int> &apa) ;

void mmCaller(vector<vector<int>> G , int u) ;

void wordFormation(vector<vector<char>> board , int x , int y , string jelenlegiszo) ; 

void wfCaller(vector<vector<char>> board) ;

bool ervenyespozicio(vector<vector<char>> G , int x , int y) ;