#include <iostream>
#include<bits/stdc++.h>
#include <cassert>
using namespace std;
# define ll long long

int a[300][1000];
int id[300];
ll a2[300];
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.
void printarr(int n1)
{
	for(int i=id[n1]-1;i>=0;i--)
	{
	cout<<a[n1][i];
	}
}
void addition(int n1)
{	int temp,carry=0;
	int i;
	id[n1]=id[n1-1];
	for(i=0;i<id[n1-1]+1;i++)
	{
		temp=a[n1-1][i]+a[n1-2][i]+carry;
		carry=temp/10;
		a[n1][i]=temp%10;		
	}
	if(a[n1][i]!=0)
	id[n1]++;
}


void call()
{
	a[1][0]=1;
	id[0]=1;
	id[1]=1;
	for(int i=2;i<=10;i++)
	{
		addition(i);
	}
}

ll call2(int n)
{	a2[0]=0;
	a2[1]=1;
	for(int i=2;i<=n;i++)
	{
	a2[i]=a2[i-1]+a2[i-2];
	}
	return a2[n];	
}

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
//    call();
//    printarr(n);
    return call2(n);
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
	memset(a,0,sizeof(a));
	for(int i=0;i<300;i++)
	id[i]=1;
	int n = 0;
	std::cin >> n;

//    std::cout << fibonacci_naive(n) << '\n';
//    test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
