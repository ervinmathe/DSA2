#include "../headers/functions.h"
#include <iostream>
#include <algorithm>

using namespace std ;

vector<vector<int>> szamitDP(const vector<int>& w, const vector<int>& v, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)) ;
    for (int i = 1 ; i <= n ; ++i)
        for (int c = 0 ; c <= W ; ++c) {
            dp[i][c] = dp[i - 1][c] ;
            if (w[i] <= c)
                dp[i][c] = max(dp[i][c], dp[i - 1][c - w[i]] + v[i]) ;
        }
    return dp ;
}

int maxErtek(const vector<vector<int>>& dp, int n, int W) {
    return dp[n][W] ;
}

vector<int> visszavezetes(const vector<vector<int>>& dp, const vector<int>& w, int n, int W) {
    vector<int> kivalasztott ;
    int c = W ;
    for (int i = n ; i >= 1 ; --i) {
        if (dp[i][c] != dp[i - 1][c]) {
            kivalasztott.push_back(i) ;
            c -= w[i] ;
        }
    }
    return kivalasztott ;
}

void kiir(const vector<int>& kivalasztott, int maxVal) {
    cout << maxVal << "\n" ;
    for (int i = kivalasztott.size() - 1 ; i >= 0 ; --i)
        cout << kivalasztott[i] << "\n" ;
}