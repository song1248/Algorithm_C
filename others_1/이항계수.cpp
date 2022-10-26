// 이항계수

#include <iostream>
#include <stdio.h>

using namespace std;


	int explore(int n, int k);


int main()
{


	int n;
	int k;
	cin >> n >> k;
	
	explore( n,  k);
	
	return 0;	
}


int explore(int n, int k)
{
	
	int **arr = new int*[n+1];
	for(int i = 0; i < n+1; i++)
	{
		arr[i] = new int[k+3];
		for(int j = 0; j < k+3; j++)
		{
			arr[i][j] = 1;
		}		
	}


	for(int i = 1; i < n+1; i++)
	{
		for(int j = 1; j < i+1; j++)
		{
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j] ;
		}		
	}


	for(int i = 0; i < n+1; i++)
	{
		for(int j = 0; j < i+2; j++)
		{
			cout << arr[i][j] << " ";
		}
		
			cout << endl;
	}
	
	return 0;
}

