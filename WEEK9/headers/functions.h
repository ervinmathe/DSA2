#pragma
#include <iostream>
#include <vector>

using namespace std ;

vector<vector<int>> szamitDP(const vector<vector<int>>& e, int n, int m) ;

int maxEsztetika(const vector<vector<int>>& dp, int n, int m) ;

vector<int> visszavezetes(const vector<vector<int>>& dp, const vector<vector<int>>& e, int n, int m) ;

void kiir(const vector<int>& elhelyezes, int maxErtek) ;