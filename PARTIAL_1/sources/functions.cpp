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



void firstExercisesRecursive() {
    
}





/*void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) {

    if(n == 0) {
        solutions.push_back(sol) ;
        printSecond(solutions[solutionCount]) ;
        return ;
    }
    for(int i = 0 ; i < moneyNotes.size(); i++) {
        if(moneyNotes[i].second == 0) {
            continue;
        } else if(validSecond(n , moneyNotes[i].first) == true) {
            sol.push_back(moneyNotes[i].first) ;
            if(find(solutions.begin() , solutions.end() , sol) != solutions.end()){
                sol.pop_back() ;
                continue ;
            }
            moneyNotes[i].second-- ;
            n -= moneyNotes[i].first ;
            secondExercises(n , moneyNotes) ;
            n += moneyNotes[i].first ;
            moneyNotes[i].second++ ;
            sol.pop_back() ;
            solutionCount++ ;
        } else continue;
    }
}*/


void secondExercises(int &n , vector<pair<int,int>> &moneyNotes) {
    vector<int> current ;
    secondExercisesBackTrack(n , moneyNotes , 0 , current) ;
}


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