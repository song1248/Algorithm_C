#include <stdio.h>
#include <iostream>

using namespace std;

int recursion(long a, long n);

int main()
{
	int tc;
	cin >> tc;
	
	while(tc--)
	{
		long a;
		cin >> a;	
		long n;
		cin >> n;	
		cout << recursion(a, n) << endl;	
	}	
	return 0;
}



int recursion(long a, long n)
{
    if(n == 0){
        return 1;
    }else{
        long temp = recursion(a, n/2);
        if(n%2 == 0) 
		{
			return (temp*temp) % 1000;
		} else {
			return (temp*temp*a) % 1000;
		} 
    }
}
