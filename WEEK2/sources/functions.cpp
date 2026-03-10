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


//HW


void hanoi(int n , char from , char helper , char destination) {
    if (n == 1) {
        cout << "1. korong: " << from << " -> " << destination << endl ;
        return ;
    }
    hanoi(n - 1 , from , destination , helper) ;
    
    cout << "Az " << n << ". korong: " << from << " -> " << destination << endl ;
    
    hanoi(n - 1 , helper , from , destination) ;
}

void merge(int arr[] , int bal , int kozep , int jobb) {
    int n1 = kozep - bal + 1 ;
    int n2 = jobb - kozep ;
    int L[n1] , R[n2] ;

    for (int i = 0 ; i < n1 ; i++) {
        L[i] = arr[bal + i] ;
    }
    for (int j = 0 ; j < n2 ; j++) {
        R[j] = arr[kozep + 1 + j] ;
    }

    int i = 0 , j = 0 , k = bal ;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++] ;
        } else {
            arr[k++] = R[j++] ;
        } 
    }
    while (i < n1) 
    {   
        arr[k++] = L[i++] ;
    }
    while (j < n2) { 
        arr[k++] = R[j++] ;
    }
}

void mergeSort(int arr[] , int bal , int jobb) {
    if (bal < jobb) {
        int kozep = bal + (jobb - bal) / 2 ;
        mergeSort(arr , bal , kozep) ;
        mergeSort(arr , kozep + 1 , jobb) ;
        merge(arr , bal , kozep , jobb) ;
    }
}


int binarySearch(int arr[] , int bal , int jobb , int x) {
    if (jobb >= bal) {
        int kozep = bal + (jobb - bal) / 2 ;

        if (arr[kozep] == x) 
        {
            return kozep ;
        }

        if (arr[kozep] > x) {
            return binarySearch(arr , bal , kozep - 1 , x) ;
        }
        return binarySearch(arr , kozep + 1 , jobb , x) ;
    }
    return -1 ;
}