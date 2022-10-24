#include <stdio.h>
#include <iostream>

using namespace std;

int explore(int *arr, int low, int high);

int main()
{
	int len_arr;
	cin >> len_arr;
	int *arr = new int[len_arr];
	for(int i=0; i<len_arr; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}

	cout << explore(arr, 0, len_arr - 1) << endl;
	
}

int explore(int *arr, int low, int high)
{
	if (low>=high)
	{
		return arr[low];
	}
	
	int mid = (low + high)/2;
	
	if (arr[mid] > arr[mid+1])
	{
		return explore(arr, low, mid);
	} else {
		return explore(arr, mid+1, high);
	}
	
}

//
//14
//12 15 20 25 32 35 40 45 31 26 12 9 7 3
