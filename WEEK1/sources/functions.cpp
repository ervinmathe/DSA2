#include "../headers/functions.h" 

using namespace std ;

int factorialRecursion(int a) {
    if(a == 0) {
        return 1 ;
    } else {
        return a * factorialRecursion(a - 1) ;
    }
}

int gcd(int a , int b) {
    if(b == 0) {
        return a ;
    } else {
        return gcd(b , a % b) ;
    }
}

long long fastPow(int base , int n) {
    if(n == 0) {
        return 1 ;
    } else {
        long long half = fastPow(base , n / 2) ;
        if(n % 2 == 0) {
            return half * half ; 
        } else {
            return base *= (half * half) ;
        }
    }
}

int nFib(int n , int a , int b) {
    if(n == 0) {
        return a ; 
    } else {
        return nFib(n - 1 , b , a + b) ;
    }
}

int digitProduct(int n) {
    if(n == 0) {
        return 1 ;
    } else {
        return (n % 10) * digitProduct(n / 10) ;
    }
}


void inverseArray(int array[] , int n) {
    if(n == 0) {
        return ;
    } else {
        cout << array[n - 1] << ' ';
        inverseArray(array , n - 1) ;
    }

}

int sumOfArray(int array[] , int n , int sum) {
    if(n == 0) {
        return sum ;
    } else {
        return sumOfArray(array , n - 1 , sum + array[n - 1]) ;
    }
}

int maxOfArray(int array[] , int n , int max) {
    if(n == 0) {
        return max ; 
    } else {
        if(array[n - 1] >= max) {
            max = array[n - 1] ;
        } else {
            max = array[n - 2] ;
        }
        return maxOfArray(array , n - 1 , max) ;
    }
}

int evenNumbers(int array[] , int n , int count) {
    if(n == 0) {
        return count ;
    } else {
        if(array[n - 1] % 2 == 0) {
            count++ ;
        }
        return evenNumbers(array , n - 1 , count) ;
    }
}

bool prime(int n) {
    if(n <= 1) {
        return false ;
    } else if(n == 2 || n == 3) {
        return true ;
    } else {
        for(int i = 2;  i < sqrt(n) ; i++) {
            if(n % i == 0) {
                return false ;
            }
        }
    }
    return true ;
}

int primeInArray(int array[] , int n , int count) {
    if(n == 0) {
        return count ;
    } else {
        if(prime(array[n - 1])) {
            count++ ;
        }
        return primeInArray(array , n - 1 , count) ;
    }
}