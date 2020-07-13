#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int ip = 0;
    int min_refills = 0;
    int prev =0;
	if(stops[0] >tank) return -1;
	if(dist-stops[stops.size()-1]>tank) return -1;    
    for(int i = 1;i<stops.size();i++)
    {	if(stops[i]-stops[i-1]>tank) return -1;	}
    for(int i= 0 ;i<stops.size();i++){
    	int actual = stops[i]-ip;
    	if(actual<tank) prev = stops[i];
    	if(actual==tank) {min_refills+=1;prev = stops[i];ip=stops[i];}
    	if(actual >tank) {
		min_refills+=1;
		ip = prev;
		prev = stops[i];
		}
	}
	if(dist - ip > tank) min_refills+=1;
	return min_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
