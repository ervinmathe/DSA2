#include "../headers/functions.h"

int firstExercises(int n , vector<int> kids , int m  , vector<int> candies) {
    int count = 0 ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(kids[i] == candies[j]) {
                count++ ;
                candies.erase(candies.begin() + j) ;
                break ;
            }
        }
    }

    return count;

}