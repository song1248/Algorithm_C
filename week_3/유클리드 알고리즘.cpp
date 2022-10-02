#include <stdio.h>
#include <iostream>

using namespace std;

int gcd(int a , int b);

int main()
{
	int testcase;
	cin >> testcase;
	
	while(testcase--)
	{
		int a;
		int b;
		cin >> a;
		cin >> b;
		
		cout << gcd(a, b) << endl;
		
		
	}
	
	return 0;
}


int gcd(int a , int b)
{
	if(b == 0)
	{
		return a;
	} else {
		return gcd(b, a % b);
	}
	
}
