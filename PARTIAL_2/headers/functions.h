#pragma
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void dfs(int jelenlegi , int visitedCount , int n , vector<vector<int>>& szomszedsagi , vector<bool>& visited ,  bool& letezik) ; 
vector<int> utvonalTerv(vector<pair<int,int>> utvonalak , bool &letezik) ;

int calculateMaxBevetel(int N, int K, int Q, vector<vector<int>>& bevetel, vector<pair<int, int>>& tiltasok) ;

void backtrackFestival(int jelenlegi , int N , int K , vector<vector<int>>& bevetel , vector<vector<int>>& szomszedsagi , vector<int>& hozzaRendeles, int jelenlegiBevetel , int& maxBevetel) ;
