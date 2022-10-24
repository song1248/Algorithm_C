#include <stdio.h>
#include <iostream>

#define max(a, b) a > b? a : b

using namespace std;

int kadain(int* arr, int arr_len);

int main()
{

	int tc;
	cin >> tc;
	while(tc--)
	{
		int arr_len;
		cin >> arr_len;
		int *arr = new int[arr_len];
		for(int i =0; i<arr_len; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;
		}	
		
		kadain(arr, arr_len);
		
	}
	
}

int kadain(int* arr, int arr_len)
{
	int max_sum = 0;
	int tmp_sum = 0;
	int tmp_start = -1;
	int start = -1;
	int end = -1;
	
	for(int i =0; i < arr_len; i++)
	{
		tmp_sum += arr[i];
		if (tmp_sum > 0){
			if(max_sum < tmp_sum)
			{
				end = i;
				max_sum = tmp_sum;
				start = tmp_start;
			}
		} else {
			tmp_sum = 0;
			tmp_start = i + 1;
		}
		
	}
	
	cout << max_sum << " " << start << " " << end << endl;
}
//3
//14 4 -6 0 2 3 -4 1 3 0 -9 4 1 -3 2
//2 -1 1
//5 -1 -1 -1 -1 0




int **arr = new arr[3];

