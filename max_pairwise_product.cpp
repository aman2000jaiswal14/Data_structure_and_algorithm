#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long int MaxPairwiseProduct(const std::vector<long long int>& number) {

    long long int n = number.size();
    long long int max1,max2;
    if(number[0]>number[1]){max1=number[0];max2=number[1];}
    else{max1=number[1];max2=number[0];}
    for(long long int i=2;i<n;i++){
    if(number[i]>max2){if(number[i]>max1){max2=max1;max1=number[i];}else{max2=number[i];}}
    }

    return max1*max2;
}

int main() {
    long long int n;
    std::cin >> n;
    std::vector<long long int> number(n);
    for (long long int i = 0; i < n; ++i) {
        std::cin >> number[i];
    }

    std::cout << MaxPairwiseProduct(number)<< "\n";
    return 0;
}
