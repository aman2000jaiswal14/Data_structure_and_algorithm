#include <iostream>
#include <vector>
using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<int> mask(values.size(),0);
  
  while(capacity>0){
  	long long int max_rate_id =  -1;
  	double max_rate_value = -1;
	for(long long int i=0;i<values.size();i++){
	  if(mask[i]!=1 && max_rate_value < double(values[i])/weights[i]){max_rate_id = i;max_rate_value = double(values[i])/weights[i];}
	  }
	if(max_rate_value==-1){return value;}  	  
	mask[max_rate_id]=1;  
	if(capacity  <=  weights[max_rate_id]) {value+= (capacity *(double)values[max_rate_id]/weights[max_rate_id]);return value;}
	else{capacity -= weights[max_rate_id];value+=values[max_rate_id];}  
  }
  
   
  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(4);
  std::cout.setf( std::ios::fixed, std:: ios::floatfield );
  std::cout << optimal_value << std::endl;
  return 0;
}
