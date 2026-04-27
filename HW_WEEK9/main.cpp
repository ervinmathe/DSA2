#include <iostream>
#include <vector>
#include "./headers/functions.h"

using namespace std ;

int main() {
    int n, W ;
    cin >> n >> W ;

    vector<int> w(n + 1), v(n + 1) ;
    for (int i = 1 ; i <= n ; ++i)
        cin >> w[i] >> v[i] ;

    auto dp = szamitDP(w, v, n, W) ;
    int maxVal = maxErtek(dp, n, W) ;
    auto kivalasztott = visszavezetes(dp, w, n, W) ;
    kiir(kivalasztott, maxVal) ;

    return 0 ;
}