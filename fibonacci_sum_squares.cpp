#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long f[100000000]={0};

long long fib(long long n) {
	n = n % 60; 
	if (n <= 1)
        return n;
	
    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    
    }

    return current % 10;
	
	
}

int fibonacci_sum_squares_fast(long long n){
	int fn = (fib(n))%10==-1?9:(fib(n))%10;
	int fn1 = (fib(n+1))%10==-1?9:(fib(n+1))%10;
	return (fn*fn1)%10;    

}


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
//    std::cout << fibonacci_sum_squares_naive(n)<<endl;
    std::cout << fibonacci_sum_squares_fast(n);

}
