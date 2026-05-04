#include "./headers/functions.h"

int main() {
    int n ;
    cin >> n ;

    vector<int> d(n + 1) ;
    for (int i = 0 ; i <= n ; i++) {
        cin >> d[i] ;
    }

    vector<vector<int>> m, s ;
    matrixChainOrder(d, m, s) ;

    cout << m[1][n] << "\n" ;
    printOptimalParens(s, 1, n) ;
    cout << "\n" ;

    return 0 ;
}