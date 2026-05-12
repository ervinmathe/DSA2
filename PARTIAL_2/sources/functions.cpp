#include "../headers/functions.h"

using namespace std;

void dfs(int jelenlegi , int visitedCount , int n , vector<vector<int>> &szomszedsagi , vector<bool> &visited ,  bool &letezik) {
    if(visitedCount == n) {
        letezik = true ; 
        return ;
    }

    for(int szomszed : szomszedsagi[jelenlegi]) { 
        if(!visited[szomszed]) {
            visited[szomszed] = true ;
            dfs()
            if(letezik) {
                return ;
            }
        }
    }

}
void utvonalTerv(vector<pair<int,int>> utvonalak , bool &letezik) {
    if (utvonalak.empty()) {
        letezik = false ;
        return ;
    }
    int n = 0 ;
    for (auto edge : utvonalak) {
        n = max(edge.first , edge.second);
    }
    vector<vector<int>> szomszedsagi(n + 1) ;
    for (auto edge : utvonalak) {
        szomszedsagi[edge.first].push_back(edge.second) ;
    }
    vector<bool> visited(n + 1, false) ;
    letezik = false ;
    visited[1] = true ; 
    if(n > 0) {
        dfs(1 , 1 , n , szomszedsagi , visited ,  letezik) ;
    }
}
