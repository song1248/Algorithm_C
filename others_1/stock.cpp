#include <stdio.h>
#include <iostream>

#define max(a,b) a>b ? a:b

using namespace std;

int stock(int*arr, int arr_len);
int main()
{
	int arr_len;
	cin >> arr_len;
	int *arr = new int[arr_len];
	for(int i =0; i < arr_len; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}
	
	stock(arr,  arr_len);
	return 0;
}


int stock(int*arr, int arr_len)
{
	int max_gap = 0;
	int min_price = 9999;
	int max_gap_idx = 0;
	for(int i = 0; i < arr_len; i++)
	{
		if (arr[i] < min_price)
		{
			min_price = arr[i];
			
		} else {
			int gap = arr[i] - min_price;
			
			if (gap>max_gap)
			{
				max_gap_idx = i;
				max_gap = gap;
			}
		}
	}
	
	cout << max_gap_idx << " " << max_gap << endl;
	
	return 0;	
}

//17
//100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97
