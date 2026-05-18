#pragma 
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>

using namespace std ;

void bfs(const vector<vector<int>>& adj, int start, int n) ;

struct Orszag {
    string nev ;
    int meret ;
    vector<string> szomszedok ;
} ;

vector<Orszag> beolvas() ;
void szomszed_szamlal(const vector<Orszag>& orszagok, int k) ;