#include <stdio.h>
#include <iostream>

#define abs(x) (((x)<0)?-(x):(x) )

using namespace std;


int weight_arr[7] = {100,50,20,10,5,2,1};
int len_weight_arr = 7;
int balance_Scale(long* arr, long len_arr);

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		long* arr = new long[n];
		for(int i = 0; i<n; i++){
			long weight;
			cin >> weight;
			arr[i] = weight;	
		}
		
		cout << balance_Scale(arr, n) << endl;
		
	}
	return 0;
}


int balance_Scale(long* arr, long len_arr)
{
	
	long left = arr[0];
	long right = arr[1];
	int idx = 2;
	
	while(idx < len_arr)
	{
		if (left <= right){
			left += arr[idx];
		}else{
			right += arr[idx];
		}
		idx++;		
	}

	int gap = (long)abs(right - left);
	

	int count = 0;
	while(gap > 0)
	{
		
		count += 1;
		for(int i=0; i < len_weight_arr; i++)
		{
			if(weight_arr[i] <= gap)
			{
				gap -= weight_arr[i];
				break;
			} 
			
		}
		
	}
	
	return count;
}
