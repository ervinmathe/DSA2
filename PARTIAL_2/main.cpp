#include "./headers/functions.h"

using namespace std;


vector<int> letezoUtvonal = {} ;
int main() {

    bool letezik = false ; 
    vector<pair<int,int>> utvonalak ;

    ifstream f ;
    f.open("input.txt") ;

    int n , m ;
    f >> n ; 
    f >> m ;

    pair<int,int> temp ;
    while(f >> temp.first >> temp.second) {
        utvonalak.push_back(temp) ;
    }

    for(auto e : utvonalak) {
        cout << e.first << ' ' << e.second << endl ;
    }

    utvonalTerv(utvonalak , &letezik) ;

    if(letezik) {
        for(auto e : letezoUtvonal) {
            cout << e << ' ' ;
        }
    } else {
        
    }

    cout << endl;
    return 0 ; 
}

