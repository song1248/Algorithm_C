#include <stdio.h>
#include <iostream>

using namespace std;

int** coin_permutate(int **dp, int *coin_arr ,int coin_count, int money);

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int coin_count;
		int money;
		cin >> money >> coin_count;
		int *coin_arr = new int[coin_count];
		coin_arr[0] = 0;
		for(int i = 1; i < coin_count+1; i++)
		{
			int num;
			cin >> num;
			coin_arr[i] = num;
		}
		
		int **dp = new int*[coin_count+1];
		for(int i = 0; i < coin_count+1 ; i++)
		{
			dp[i] = new int[money+1];
			for(int j = 0; j <money+1; j++)
			{
				dp[i][j] = 0;
			}
		}
		
		
		cout << coin_permutate(dp, coin_arr ,coin_count, money)[coin_count][money] << endl;
		
	}
	
	
	
	return 0;
}



int** coin_permutate(int **dp, int *coin_arr ,int coin_count, int money)
{
	dp[0][0] = 1;
	
	for(int i = 1; i < coin_count + 1; i++)
	{
		for(int j = 0; j < money+1 ; j++)
		{
			int cur_money = coin_arr[i];
			
			if(j >= cur_money)
			{	
				dp[i][j] = dp[i][j-cur_money] + dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
			
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return (int**)dp;
}
