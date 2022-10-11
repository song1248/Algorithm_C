#include <stdio.h>
#include <iostream>

using namespace std;

int binarysearch(int *arr, int num, int start_idx, int end_idx);

int main(){
	
	int tc;
	cin >> tc;
	
	while(tc--){
		int len_input, num;
		cin >> len_input >> num;
		
		int *num_arr = new int[len_input];
		
		for(int i = 0; i < len_input; i++){
			int tmp;
			cin >> tmp;
			num_arr[i] = tmp;
		}
		
		cout << binarysearch(num_arr, num, 0, len_input-1) << endl;
	} 
	
	return 0;
}

int binarysearch(int *arr, int num, int start_idx, int end_idx)
{
	
	int mid = (start_idx + end_idx)/2;
	if (start_idx>=end_idx){
		if (arr[mid] == num)
			return mid;
		else
			return -1;		
	}
	
	
	if (arr[mid] > num)
	{
		binarysearch(arr, num, start_idx, mid-1);
	}
	else if (arr[mid] < num)
	{
		binarysearch(arr, num, mid+1, end_idx);
	}
	else
	{
		if (arr[mid] == num)
			return mid;
		else
			return -1;
	}
		

}
