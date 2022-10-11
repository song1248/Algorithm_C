#include <stdio.h>
#include <iostream>

using namespace std;

int max(int arr[], int low, int high);
int k_max;

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

		k_max = 0;
		
		int m = max(arr, 0 ,len_arr-1);
		
		k_max = (k_max > m) ? k_max : m;
		
		cout << k_max << endl;
		
		
	}
	
	return 0;
}

int max(int arr[], int low, int high)
{
	// Áß¾ÓºÎÅÍ ÃÖ´ëÅ½»ö
	// ¿ÞÂÊÃÖ´ëÅ½»ö
	// ¿À¸¥ÂÊ ÃÖ´ëÅ½»ö  
	int mid;
	mid = (low + high) / 2;
	
	if (low == high)
	{
		return arr[low];
	}
	
	int l = max(arr, low, mid);
	int r = max(arr, mid+1, high);
	
	k_max = (k_max > l) ? k_max : l;
	k_max = (k_max > r) ? k_max : r;
	
	// ¿ÞÂÊ  
	int k = 0;
	int l_k_max = 0;
	for(int i = mid; i >= low ; i--)
	{
		k += arr[i];
		l_k_max = (l_k_max > k) ? l_k_max : k;
	}
	
	// ¿À¸¥ÂÊ  
	k = 0;
	int r_k_max = 0;
	for(int i = mid+1; i <= high; i++)
	{
		k += arr[i];
		r_k_max = (r_k_max > k) ? r_k_max : k;
	} 	 
	
	return r_k_max + l_k_max;
}
