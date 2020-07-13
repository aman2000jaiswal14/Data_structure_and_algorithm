#include <iostream>
#include<bits/stdc++.h>
#include<cmath> 
using namespace std;

long long int pissano_number(long long int m){
	long long temp,prev=0,cur=1;
	for(long long int i=0;i<m*m;i++){
		temp=cur;
		cur=(prev+cur)%m;
		prev=temp;
		if(prev==0 and cur==1){return i+1;}
				
	}
	
}
long long get_fibonacci_huge_fast(long long n,long long m) {
	n = n % pissano_number(m); 
	if (n <= 1)
        return n;
	
    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    
    }

    return current % m;
	
	
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
//    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
