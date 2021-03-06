#include <iostream>
#include<bits/stdc++.h>
using namespace std;
# define ll long long

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd_fast(int a,int b){
	int temp;
	if(a==0){return b;}
	else if(b==0){return a;}
	else{
	
		if(a>b){a=a%b;gcd_fast(a,b);}
		else{b=b%a;gcd_fast(a,b);}
	}
}
int main() {
  int a, b;
  std::cin >> a >> b;
//  std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;  
  return 0;
}
