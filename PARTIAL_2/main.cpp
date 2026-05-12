#include "./headers/functions.h"
#include <algorithm>

using namespace std;

int main() {

    /*bool letezik = false ; 
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


    vector<int> ut = utvonalTerv(utvonalak , letezik) ;

    if(letezik) {
        for(auto e : ut) {
            cout << e << ' ' ;
        }
    } else {
        cout << "Nem letezik ilyen ut" ;
    }

    cout << endl;
    f.close() ;
*/

    ifstream file ;
    file.open("input2.txt") ;
    int n , k , q ;
    f >> n >> k >> q ;

    vector<vector<int>> fesztival ;

    for(int i = 0 ; i < n ; i++) {
        int temp ;
        while(f >> temp) {
            fesztival[i].push_back(temp) ;
        }
    }

    vector<pair<int , int> tilos ;

    pair<int , int > temp ;
    while(file >> temp.first >> temp.second) {
        tilos.push_back(temp) ;
    }


    int osszertek = calculateMax(n , k , q , fesztival , tilos) ;

    cout << osszertek ;

    return 0 ; 
}



