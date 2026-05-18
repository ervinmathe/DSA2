#include "./headers/functions.h"

using namespace std ;

void feladat3() {
    int n, m ;
    cin >> n >> m ;

    vector<vector<int>> adj(n) ;

    for (int i = 0 ; i < m ; i++) {
        int u, v ;
        cin >> u >> v ;
        adj[u].push_back(v) ;
    }

    bfs(adj, 0, n) ;
}

void feladat4() {
    int k ;
    cin >> k ;

    vector<Orszag> orszagok = beolvas() ;
    szomszed_szamlal(orszagok, k) ;
}

int main() {
    feladat3() ;
    feladat4() ;
    return 0 ;
}