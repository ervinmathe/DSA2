#include "../headers/functions.h"

using namespace std ;

void bfs(const vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false) ;
    queue<int> q ;

    visited[start] = true ;
    q.push(start) ;

    while (!q.empty()) {
        int u = q.front() ;
        q.pop() ;
        cout << u << " " ;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true ;
                q.push(v) ;
            }
        }
    }
    cout << endl ;
}

vector<Orszag> beolvas() {
    int n ;
    cin >> n ;

    vector<Orszag> orszagok(n) ;

    for (int i = 0 ; i < n ; i++) {
        cin >> orszagok[i].nev >> orszagok[i].meret ;
    }

    for (int i = 0 ; i < n ; i++) {
        string s ;
        cin >> s ;
        while (cin >> s && s != "0") {
            orszagok[i].szomszedok.push_back(s) ;
        }
    }

    return orszagok ;
}

void szomszed_szamlal(const vector<Orszag>& orszagok, int k) {
    map<string, int> meret_map ;
    map<string, int> idx_map ;
    for (int i = 0 ; i < (int)orszagok.size() ; i++) {
        meret_map[orszagok[i].nev] = orszagok[i].meret ;
        idx_map[orszagok[i].nev] = i ;
    }

    map<string, bool> latogatott ;
    queue<string> q ;

    q.push(orszagok[0].nev) ;
    latogatott[orszagok[0].nev] = true ;

    while (!q.empty()) {
        string jelenlegi = q.front() ;
        q.pop() ;

        int idx = idx_map[jelenlegi] ;
        int darab = 0 ;

        for (const string& szomszed : orszagok[idx].szomszedok) {
            if (meret_map.count(szomszed) && meret_map[szomszed] > k) {
                darab++ ;
            }
            if (!latogatott[szomszed] && idx_map.count(szomszed)) {
                latogatott[szomszed] = true ;
                q.push(szomszed) ;
            }
        }

        cout << jelenlegi << ": " << darab << endl ;
    }
}