#include <stdio.h>
#include <iostream>

using namespace std;

int max(int arr[], int low, int high);

main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int len_arr;
		cin >> len_arr;
		int *arr = new int[len_arr];
		for(int i =0; i < len_arr; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;
		}
		
		cout << max(arr, 0, len_arr-1) << endl;
		
	}
	return 0;
}


int max(int arr[], int low, int high)
{
	
	if (low >= high)
	{
		return arr[low];
	}
	
	int mid;
	mid = (low + high) / 2;
	
	int a = max(arr, low, mid);
	int b =	max(arr, mid+1, high);
	
	if( a>= b)
	{
		return a;
	} else {
		return b;
	}
}


