#include <iostream>
#include <vector>
using std::vector;
#include<bits/stdc++.h>
using namespace std;
long long f[100000000]={0};

long long fib(long long n) {
	n = n %60; 
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int first = (fib(to+2)-1==-1?9:fib(to+2)-1)%10;
    int sub  = (fib(from-1+2)-1==-1?9:fib(from-1+2)-1)%10;

    return first-sub<0?10+first-sub:first-sub;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    
}
