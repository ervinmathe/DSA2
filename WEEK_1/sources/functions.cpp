#include "../headers/functions.h"


int factorialRecursion(int a) {
    if(a == 0) {
        return 0 ;
    } else {
        return a * factorialRecursion(a - 1) ;
    }
}