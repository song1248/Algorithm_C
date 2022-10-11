#include <stdio.h>
#include <iostream>

using namespace std;

int kadane(int arr[], int len_arr);

int main(){
	int tc, len_arr;
	cin >> tc;	
	while(tc--)
	{

		cin >> len_arr;
		int *arr = new int[len_arr];
		for(int i = 0; i < len_arr; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;  
		}
		
		kadane(arr, len_arr);
		
	}
	
	return 0;
}

int kadane(int arr[], int len_arr)
{
	int tmp_start = 0;
	int start_idx = -1;
	int end_idx = -1;
	int sub_sum = 0;
	int max_sub_sum = 0;
	
	for(int i = 0; i<len_arr ;i++)
	{
		
		if (arr[i] + sub_sum < arr[i])
		{
			tmp_start = i;
			sub_sum = arr[i];
		} else {
			sub_sum = arr[i] + sub_sum;
		}

		// max_sub_sum보다 sub_sum이 커지면 update
		if(sub_sum > max_sub_sum){
			max_sub_sum = sub_sum;
			start_idx = tmp_start;
			end_idx = i;
		}		
		

	}
	
	for(int i = start_idx; i<end_idx ;i++)
	{
		if(arr[i] != 0){
			break;
		} else {
			start_idx += 1;
		}
	}
	
	cout << max_sub_sum << " " << start_idx << " " << end_idx << endl;
	
	return max_sub_sum;
}
