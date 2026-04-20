#include "../headers/function.h"
#include <iostream>


void melysegiMenet(vector<vector<int>>& G, int u, vector<int>& szin, vector<int>& apa) {
    szin[u] = 1 ;
    
    for (int v : G[u]) {
        if (szin[v] == 0) { 
            apa[v] = u ;
            melysegiMenet(G , v , szin , apa) ;
        }
    }
    
    szin[u] = 2 ;
}

void mmCaller(vector<vector<int>> G , int u) {
    int n = G.size() ;
    vector<int> szin(n , 0) ;
    vector<int> apa(n , -1) ;
    for(int i = 0 ; i < n ; i++) {
        if(szin[i] == 0) {
            melysegiMenet(G , i , szin , apa) ;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        cout << i << " csucs apja: " << apa[i] << endl ;
    }
}




void wordFormation(vector<vector<char>> board , int x , int y , string jelenlegiszo , ) {
    
}

void wfCaller(vector<vector<char>> board) {
    int sorok = board.size() ;
    int oszlopok = board[0].size() ;
    bool viewed[sorok][oszlopok] = {false} ; 
    

}


bool ervenyespozicio(vector<vector<char>> G , int x , int y) {
    int n = G.size() ;
    int m = G[0].size() ;

    return x >= 0 && x < n && y >= 0 && y < m ;
}
