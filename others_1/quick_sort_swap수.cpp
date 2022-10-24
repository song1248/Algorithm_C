#include <stdio.h>
#include <iostream>

#define swap(a, b) {int tmp=a; a=b; b=tmp;}

int ssss = 0;
int arr_len;

using namespace std;

void quicksort(int* A, int low, int high);
int partition_Lomuto(int* A, int low, int high);

int main()
{
	
	cin >> arr_len;
	int *arr = new int[arr_len];
	for(int i =0; i<arr_len; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}	

	quicksort(arr, 0, arr_len-1);
	
	cout << ssss << endl;
}

void quicksort(int* A, int low, int high)
{
	if (low >= high)
		return;
	int p = partition_Lomuto(A, low, high);
	quicksort(A, low, p-1);
	quicksort(A, p+1, high)	;
}

int partition_Lomuto(int* A, int low, int high)
{
		int pivot = A[low];
		int j = low;
		for( int i = low+1; i<= high; i++){
			if (A[i] < pivot)
			{
				j = j + 1;
				swap (A[i], A[j]);
				for(int i =0; i<arr_len; i++)
				{
					cout << A[i] << " ";
				}
				cout << endl;
				ssss++;					
			}	
		}
		int pivot_pos = j;
		swap(A[pivot_pos] , A[low]);  // swap ¿¬»ê++
		for(int i =0; i<arr_len; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
		ssss++;
	return pivot_pos;
}

