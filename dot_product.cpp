#include <algorithm>
#include <iostream>
#include <vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

long long minimum(vector<int> x, vector<int> &mask)
{	int min = INT_MAX;
	int id = -1;
	for(size_t i = 0 ;i<x.size();i++)
	{
		if(mask[i]!=1 && x[i]<=min){min = x[i];id=i;}
	}
	mask[id]=1;
	return min;
}
long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  vector<int> maska(a.size(),0);
  vector<int> maskb(b.size(),0);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) minimum(a,maska) * minimum(b,maskb));
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
