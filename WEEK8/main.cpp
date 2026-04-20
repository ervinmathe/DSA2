#include <iostream>
#include "./headers/function.h"
#include <vector>

using namespace std;

int main() {
    
    /*vector<vector<char>> board = {
  {'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'}
    } ;*/

    /*vector<vector<int>> G = {{4 , 2 , 3} , {} , {} , {} , {}} ;
    cout << "DFS: " << endl << endl ;
    mmCaller(G , 0) ;  */
    
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    } ;

    wfCaller(board) ;
    return 0 ;
}