#include <stdio.h>
#include <iostream>

#define min(a,b) a < b ? a:b


using namespace std;

int exchange(int coin_num, int money, int* coin_arr);

int main()
{
	
	int coin_num;
	cin >> coin_num;
	int money;
	cin >> money;
	int *coin_arr = new int[coin_num];
	for(int i = 0; i < coin_num; i++)
	{
		int c;
		cin >> c;
		coin_arr[i] = c;
	}	
	
	exchange(coin_num,  money, coin_arr);
	
	
	return 0;	
}


int exchange(int coin_num, int money, int* coin_arr)
{

	
	
	int *arr = new int[money+1];
	arr[0] = 0;
	for(int i = 1; i < money+1;i++)
	{
		int min_val = 9999;
		for(int j = 0; j < coin_num; j++)
		{
			if(i - coin_arr[j] >= 0)
			{
				min_val = min(min_val, arr[i- coin_arr[j]]);
			}
		}
		arr[i] = min_val+1;
	}
	
	for(int i = 0; i < money+1;i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << arr[money] << endl;
}

 
