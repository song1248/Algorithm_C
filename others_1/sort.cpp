#include <stdio.h>
#include <iostream>

using namespace std;

int bubble_sort(int *arr, int arr_len);

int main()
{
	int tc;
	cin >> tc;
	
	while(tc--)
	{
		
		
		int len_arr;
		cin >> len_arr;
		
		int *arr = new int[len_arr];
		for(int i = 0; i<len_arr; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;
		}
		
		bubble_sort(arr, len_arr);
	}

	return 0;
}



int bubble_sort(int* arr, int arr_len)
{
	for(int i = arr_len; i>0 ; i--)
	{
		for(int j = 0; j < i-1 ; j++)
		{
			if( arr[j] > arr[j+1] ){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	for(int i = 0; i<arr_len ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}

//
//int improved_bubble_sort_1(int* arr, int arr_len)
//{
//	
//}
//
//int improved_bubble_sort_2(int* arr, int arr_len)
//{
//	
//}
//
//
//
//
//int cocktail_shake_sort(int* arr, int arr_len)
//{
//	
//}
//
//int comb_sort(int* arr, int arr_len)
//{
//	
//}
//
//
//int selection_sort(int* arr, int arr_len)
//{
//	
//	
//}
//
//
//int insertion_sort(int* arr, int arr_len)
//{
//	
//}
//
//int shel_sort(int* arr, int arr_len)
//{
//	
//}




