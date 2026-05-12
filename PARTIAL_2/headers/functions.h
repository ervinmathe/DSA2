#pragma
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void dfs(int jelenlegi , int visitedCount , int n , vector<vector<int>>& szomszedsagi , vector<bool>& visited ,  bool& letezik) ; 
vector<int> utvonalTerv(vector<pair<int,int>> utvonalak , bool &letezik) ;

int calculateMax(int N, int K, int Q, vector<vector<int>>& bevetel, vector<pair<int , int>>& tiltasok);


