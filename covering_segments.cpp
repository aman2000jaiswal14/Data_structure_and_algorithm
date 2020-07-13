#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};
long long minimum(vector<Segment> x, vector<int> &mask)
{	int min = INT_MAX;
	int id = -1;
	for(size_t i = 0 ;i<x.size();i++)
	{
		if(mask[i]!=1 && x[i].end <= min){min = x[i].end;id=i;}
	}
	if(id == -1)
	return -1;
	for(size_t i = 0;i < x.size();i++)
	{
		if(min>=x[i].start and min<=x[i].end)
		mask[i] = 1;
	}
	return min;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector<int> masks(segments.size(),0);
  
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
  	long long mpt = minimum(segments , masks);
  	if(mpt == -1)
  	break;
    
	points.push_back(mpt);
//    points.push_back(segments[i].end);
	
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
