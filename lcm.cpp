#include <iostream>
#include<bits/stdc++.h>
long long int gcd_fast(long long int a,long long int b){
	long long int temp;
	if(a==0){return b;}
	else if(b==0){return a;}
	else{
	
		if(a>b){a=a%b;gcd_fast(a,b);}
		else{b=b%a;gcd_fast(a,b);}
	}
}
long long lcm_fast(long long int a, long long int b) {
	return (a*b)/gcd_fast(a,b);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;  
  return 0;
}
