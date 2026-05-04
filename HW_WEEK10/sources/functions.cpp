#include "../headers/functions.h"

void matrixChainOrder(const vector<int> &d, vector<vector<int>> &m, vector<vector<int>> &s) {
    int n = d.size() - 1 ;
    m.assign(n + 1, vector<int>(n + 1, 0)) ;
    s.assign(n + 1, vector<int>(n + 1, 0)) ;

    for (int len = 2 ; len <= n ; len++) {
        for (int i = 1 ; i <= n - len + 1 ; i++) {
            int j = i + len - 1 ;
            m[i][j] = INT_MAX ;
            for (int k = i ; k < j ; k++) {
                int cost = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j] ;
                if (cost < m[i][j]) {
                    m[i][j] = cost ;
                    s[i][j] = k ;
                }
            }
        }
    }
}

void printOptimalParens(const vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "A" << i ;
    } else {
        cout << "(" ;
        printOptimalParens(s, i, s[i][j]) ;
        printOptimalParens(s, s[i][j] + 1, j) ;
        cout << ")" ;
    }
}