#include "../headers/functions.h"

using namespace std;

vector<int> letezoUtvonal = {} ;

void dfs(int jelenlegi , int visitedCount , int n , vector<vector<int>>& szomszedsagi , vector<bool>& visited ,  bool& letezik) {
    if(visitedCount == n) {
        letezik = true ; 
        return ;
    }

    for(int szomszed : szomszedsagi[jelenlegi]) { 
        if(!visited[szomszed]) {
            visited[szomszed] = true ;
            letezoUtvonal.push_back(szomszed) ; 
            dfs(szomszed , visitedCount + 1 , n , szomszedsagi , visited , letezik) ;
            if(letezik) {
                return ;
            }
            letezoUtvonal.pop_back() ;
            visited[szomszed] = false ;
        }
    }

}
vector<int> utvonalTerv(vector<pair<int,int>> utvonalak , bool &letezik) {
    if (utvonalak.empty()) {
        letezik = false ;
        return letezoUtvonal ;
    }
    int n = 0 ;
    for (auto edge : utvonalak) {
        n = max(n, max(edge.first, edge.second));
    }
    vector<vector<int>> szomszedsagi(n + 1) ;
    for (auto edge : utvonalak) {
        szomszedsagi[edge.first].push_back(edge.second) ;
    }
    vector<bool> visited(n + 1, false) ;
    letezik = false ;
    visited[1] = true ; 
    if(n > 0) {
        letezoUtvonal.push_back(1) ;
        dfs(1 , 1 , n , szomszedsagi , visited ,  letezik) ;
    }

    return letezoUtvonal ; 
}

void backtrackFestival(int jelenlegi , int N , int K , vector<vector<int>>& bevetel , vector<vector<int>>& szomszedsagi , vector<int>& hozzaRendeles, int jelenlegiBevetel , int& maxBevetel) {
    if(jelenlegi == N + 1) {
        if(jelenlegiBevetel > maxBevetel) {
            maxBevetel = jelenlegiBevetel ;
        }
        return ;
    }

    for(int attrakcio = 0 ; attrakcio < K ; attrakcio++) {
        bool jo = true ; 
        for(int szomszed : szomszedsagi[jelenlegi]) {
            if(hozzaRendeles[szomszed] == attrakcio) {
                jo = false ; 
                break ;
            }
        }

        if(jo) { 
            hozzaRendeles[jelenlegi] = attrakcio ;
            backtrackFestival(jelenlegi + 1 , N , K , bevetel , szomszedsagi , hozzaRendeles , jelenlegiBevetel + bevetel[jelenlegi - 1][attrakcio] , maxBevetel)  ; 
            hozzaRendeles[jelenlegi] = -1 ; 
        }
    }
}

int calculateMaxBevetel(int N , int K , int Q , vector<vector<int>>& bevetel , vector<pair<int , int>>& tiltasok) {
    vector<vector<int>> szomszedsagi(N + 1) ;
    for (auto t : tiltasok) {
        szomszedsagi[t.first].push_back(t.second) ;
        szomszedsagi[t.second].push_back(t.first) ;
    }
    
    int maxBevetel = 0 ;
    vector<int> hozzaRendeles(N + 1 , -1) ;

    backtrackFestival(1 , N , K , bevetel , szomszedsagi , hozzaRendeles , 0 , maxBevetel) ;
    
    return maxBevetel ;
}
