#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;
using std::vector;
using std::string;

string greaterno(string x,string y)
{	int comp = x.compare(y);
	if(comp==0) return x;
	for(int i=0;i<x.size()+y.size();i++)
	{
		if(x[i%x.size()]>y[i%y.size()])
		return x;
		else if(x[i%x.size()]<y[i%y.size()])
		return y;
	}
	return x;
//	else if(comp==-1) return y;
//	else if(comp==1)  return x;
}
string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  vector<int> mask(a.size(),0);
  long long id;
  while(a.size()>0){
  	string gt = " ";
  for (size_t i = 0; i < a.size(); i++) {
  		if(mask[i]!=1){
    	string gt1 = greaterno(gt,a[i]);
		if(gt1.compare(gt)!=0){
    		id = i;
    		gt = gt1;}
    	}
	}
	  if(gt==" ")
	  break;
	  mask[id]=1;
	  ret<<gt;
	}
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  	std::cout <<largest_number(a);
}
