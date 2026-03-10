#include "../headers/functions.h"

using namespace std;


const string aeiou = "aeiou" ;

void firstExercise(vector<int> arr , int n) {
    //for(int i = 0 ; i < )
    if(arr.size() == n) {
        printSolutionForFirst(arr) ;
        return ;
    }

    
    int startElement = arr.empty() ? 0 : arr.back() + 1 ;
    for(int i = startElement ; i <= 9; i++) {
        if(firstValid(arr)) {
            arr.push_back(i) ;
            firstExercise(arr , n) ;
            arr.pop_back() ;
        }
    }
}

bool firstValid(vector<int> arr) {
    if(arr.size() == 1) {
        return true ;
    }


    for(int i = 1 ; i < arr.size() ; i++) {
        if(arr[i - 1] > arr[i]) {
            return false ;
        }
    }

    return true ;
}


void printSolutionForFirst(vector<int> arr)
{
    cout << '[' ;
    for(int a : arr) {
        cout << a << " " ;
    }
    cout << ']' << endl ;
}


void secondExercise(string word) {
    if(word.size() == 5) {
        cout << word << endl ;
        return ;
    }

    for(char c : aeiou) {
        word += c ;
        secondExercise(word) ;
        word.pop_back() ;
    }

    
}


void thirdExercise(int sum , vector<int> arr) {

    if(arr.size() == 10) {
        printSolutionforThird(arr) ;
        return ;
    }

    for(int i = 0 ; i < 9 ; i++) {
        if(arr.size() == 0 && i == 0) {
            continue;
        }
        arr.push_back(i) ;
        if(validThird(sum , arr)) {
            thirdExercise(sum , arr) ;
        }
        arr.pop_back() ;
    }
}

bool validThird(int sum , vector<int> arr) {
    int temp ;
    for(int a : arr) {
        temp += a ;
    }

    if(temp < sum) {
        return true ;
    } else {
        return false ;
    }
}

void printSolutionforThird(vector<int> arr) {
    for(int a : arr) {
        cout << a ; 
    }
    cout << endl;
}
