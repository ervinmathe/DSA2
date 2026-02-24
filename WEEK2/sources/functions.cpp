#include "../headers/functions.h"


using namespace std;

int maxWithIndex(int array[] , int startIndex , int endIndex) {
    if(startIndex == endIndex) {
        return startIndex ;
    } else {
        int m1 = maxWithIndex(array , startIndex , (startIndex + endIndex) / 2) ;
        int m2 = maxWithIndex(array , (startIndex + endIndex) / 2 + 1 , endIndex) ;
        if(array[m1] > array[m2]) {
            return m1 ; 
        } else {
            return m2 ;
        }
    } 
}


int maxWithValue(int array[] , int startIndex , int endIndex) {
    if(startIndex == endIndex) {
        return array[startIndex] ;
    } else {
        int m1 = maxWithValue(array , startIndex , (startIndex + endIndex) / 2) ;
        int m2 = maxWithValue(array , (startIndex + endIndex) / 2 + 1 , endIndex) ;
        if(m1 > m2) {
            return m1 ;
        } else {
            return m2 ;
        }
    }
}


int sumOfArray(int array[] , int startIndex , int endIndex) {
    if(startIndex == endIndex) {
        return array[startIndex] ;
    } else {
        int m1 = sumOfArray(array , startIndex , (startIndex + endIndex) / 2) ;
        int m2 = sumOfArray(array , (startIndex + endIndex) / 2 + 1 , endIndex) ;

        return m1 + m2 ;
    }
}


int oddNumbers(int array[] , int startIndex , int endIndex) {
    if(startIndex == endIndex) {
        return array[startIndex] % 2 == 0 ? 0 : 1 ;
    } else {
        return oddNumbers(array , startIndex , (startIndex + endIndex) / 2) + oddNumbers(array , (startIndex + endIndex) / 2 + 1, endIndex) ;

    }
}



void Hanoi(int k , int source , int destination , int helper) {
    if(k == 1) {
        cout << "('," << source << ",','," << destination << ",')" ;
    } else {
        Hanoi(k - 1 , source , helper , destination) ;
        cout << "('," << source << ",','," << destination << ",')" ;
        Hanoi(k - 1 , helper , destination , source) ;
    }
}