#include "../headers/functions.h"


//Solution for the first exercises of the partial
int firstExercises() {
    int n , m;
    vector<int> kids , candies ;
    ifstream file ;
    file.open("input1.txt") ;

    file >> n ;
    for(int i = 0 ; i < n ; i++) {
        int temp ;
        file >> temp ;
        kids.push_back(temp) ;
    }

    file >> m ;
    for(int i = 0 ; i < n ; i++) {
        int temp ;
        file >> temp ;
        candies.push_back(temp) ;
    }

    int count = countMatches(kids , candies , 0 , n , m) ;

    return count;
}

//helper function for the countMatches function
int findCandyIndex(vector<int> &candies , int j , int m , int need) {
    if(j == m) return -1 ;
    if(need <= candies[j]) return j ;
    return findCandyIndex(candies , j + 1 , m , need) ;
}

//instead of a double 'for' , I search for the  matching candies for the kids recursively.
///Although I do think a double for would suit the exercises better, because of the criteria of the partial
//I solved it recursively
int countMatches(vector<int> &kids , vector<int> &candies , int i , int n , int m) {
    if(i == n) return 0 ;

    int idx = findCandyIndex(candies , 0 , m , kids[i]) ;
    if(idx == -1) return countMatches(kids , candies , i + 1 , n , m) ;

    candies[idx] = 0 ;
    return 1 + countMatches(kids , candies , i + 1 , n , m) ;
}


/// Solution for the second exercises of the partial
void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) {
    vector<int> current ;
    secondExercisesBackTrack(n , moneyNotes , 0 , current) ;
}

//the backtracking algorithm
void secondExercisesBackTrack(int remaining , vector<pair<int,int>> &moneyNotes , int startIndex , vector<int> &current) {
    if(remaining == 0) {
        printSecond(current) ;
        return ;
    } 

    for(int i = startIndex ; i < moneyNotes.size() ; i++) {
        int noteValue = moneyNotes[i].first ;
        int noteCount = moneyNotes[i].second ;
        if(noteCount > 0 && validSecond(remaining , noteValue)) {
            current.push_back(noteValue) ;
            moneyNotes[i].second-- ;
            secondExercisesBackTrack(remaining - noteValue , moneyNotes , i , current) ;
            moneyNotes[i].second++ ;
            current.pop_back() ;
        }
    }
}

//a print function that prints a solution
void printSecond(vector<int> solution) {
    for(int note : solution) {
        cout << note << " " ;
    }

    cout << endl << endl ;
}

//a validating function for the backtracking algorithm that checks if the input sum is still above 0
bool validSecond(int n , int note) {
    if(n - note < 0) {
        return false ;
    }
    return true ;
}