#include <iostream>
#include <vector>
# include<bits/stdc++.h>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  long long ith =1; 
  while(n>0){
  	if(ith<=n)
  	{
  		n = n-ith;
  		summands.push_back(ith);
  		ith++;
	}
	else{
		summands[ith-2] += n;
		break;
	}
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
