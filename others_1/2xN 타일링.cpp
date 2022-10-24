#include <stdio.h>
#include <iostream>

using namespace std;

int explore(int *dp, int n);

int main()
{
	int num;
    cin >> num;
    int *dp = new int[num];
    explore(dp, num);
    
}


int explore(int *dp, int n)
{
	int tmp_num = 2;
	
	dp[0] = 1;
	dp[1] = 2;
	while(tmp_num < n) 
	{		
		dp[tmp_num] = (dp[tmp_num-1] + dp[tmp_num-2])%10007;
		tmp_num++;
	}	
	
	cout << dp[n-1]%10007;
	return 0;
}
