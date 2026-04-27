#pragma
#include <iostream>
#include <vector>

using namespace std ;

vector<vector<int>> szamitDP(const vector<int>& w, const vector<int>& v, int n, int W) ;

int maxErtek(const vector<vector<int>>& dp, int n, int W) ;

vector<int> visszavezetes(const vector<vector<int>>& dp, const vector<int>& w, int n, int W) ;

void kiir(const vector<int>& kivalasztott, int maxVal) ;