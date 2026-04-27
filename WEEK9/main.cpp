#include <iostream>
#include <vector>
#include <climits>
#include "./headers/functions.h"

using namespace std ;

int main() {
    int n, m ;
    cin >> n >> m ;

    vector<vector<int>> e(n + 1, vector<int>(m + 1, 0)) ;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= m ; ++j)
            cin >> e[i][j] ;

    auto dp = szamitDP(e, n, m) ;
    int maxErtek = maxEsztetika(dp, n, m) ;
    auto elhelyezes = visszavezetes(dp, e, n, m) ;
    kiir(elhelyezes, maxErtek) ;

    return 0 ;
}