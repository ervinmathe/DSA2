#include <iostream>
#include "headers/functions.h"


using namespace std;

int main() {

    
    int array[] = {6, 6, 3, 64, 78, 4, 4, 3, 87, 4} ;
    int n = 10 ;

    //cout << maxWithIndex(array , 0 , n - 1) << endl ;
    //cout << maxWithValue(array , 0 , n - 1) << endl ;
    //cout << sumOfArray(array , 0 , n - 1) << endl ;
    //cout << oddNumbers(array , 0 , n - 1) << endl ;
    hanoi(5 , 'F' , 'H' , 'D') ;

    return 0 ;
}