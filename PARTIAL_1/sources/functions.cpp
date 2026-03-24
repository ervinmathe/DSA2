#include "../headers/functions.h"

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

    int count = 0 ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(kids[i] <= candies[j]) {
                count++ ;
                candies[j] = 0 ;
                break ;
            }
        }
    }

    return count;

}


vector<vector<int>> solutions ;
vector<int> sol ;
int solutionCount = 0 ;

void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) {

    if(n == 0) {
        solutions.push_back(sol) ;
        printSecond(solutions[solutionCount]) ;
        return ;
    }
    for(int i = 0 ; i < moneyNotes.size(); i++) {
        if(moneyNotes[i].second == 0) {
            continue;
        } else if(validSecond(n , moneyNotes[i].first) == true && find(solutions.begin() , solutions.end() , sol)) {
            sol.push_back(moneyNotes[i].first) ;
            moneyNotes[i].second-- ;
            n -= moneyNotes[i].first ;
            secondExercises(n , moneyNotes) ;
            n += moneyNotes[i].first ;
            moneyNotes[i].second++ ;
            sol.pop_back() ;
            solutionCount++ ;
        } else continue;
    }
}


void printSecond(vector<int> solution) {
    for(int note : solution) {
        cout << note << " " ;
    }

    cout << endl << endl ;
}

bool validSecond(int n , int note) {
    if(n - note < 0) {
        return false ;
    }
    return true ;
}