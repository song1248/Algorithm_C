#include <stdio.h>
#include <iostream>

using namespace std;

int quicksort_H(int* A, int low, int high);
int quicksort_L(int* A, int low, int high);
int partition_Hoare(int* A, int low, int high);
int partition_Lomuto(int *A, int low, int high);

int swap1 = 0;
int swap2 = 0;
int compare1 = 0;
int compare2 = 0;


int main(){
	
	int tc;
	cin >> tc;
	while(tc--){

		int len;
		cin >> len;
		int *arr1 = new int[len];
		int *arr2 = new int[len];
		
		for(int i = 0; i < len; i++)
		{
			int num;
			cin >> num;
			arr1[i] = num;
			arr2[i] = num;	
		}
	
		swap1 = 0;
		swap2 = 0;
		compare1 = 0;
		compare2 = 0;
		
		
		quicksort_L(arr1, 0, len-1);
		quicksort_H(arr2, 0, len-1);
//		for(int i = 0; i < len; i++)
//		{
//			cout <<	arr2[i] << " ";
//		}
//		cout <<endl;
			
		cout << swap1 << " " << swap2 << " " << compare1 << " " << compare2 << endl;
		
	}
	
	
	return 0;
}


int quicksort_H(int* A, int low, int high){
	if(low >= high)
	{
		return 0;
	}
	
	int p = partition_Hoare(A, low, high);
	quicksort_H(A, low, p);
	quicksort_H(A, p+1, high);

	return 0;
}


int quicksort_L(int* A, int low, int high){
	if(low >= high)
	{
		return 0;
	}
	
	int p = partition_Lomuto(A, low, high);
	quicksort_L(A, low, p-1);
	quicksort_L(A, p+1, high);

	return 0;
}

int partition_Hoare(int* A, int low, int high)
{
	int pivot = A[low];
	int i = low - 1;
	int j = high + 1;

	
	while(true)
	{
		do{
			i = i + 1;
		}
		while((compare1++ | true) & A[i] < pivot);

		do{
			j = j - 1;
		}
		while((compare1++ | true) & A[j] > pivot);
		
		if( i < j)
		{
			swap1++;
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		} else {
			return j;
		}	
	}
}


int partition_Lomuto(int* a, int low, int high)
{
int i, j;
int pivot, pivotPos, tmp;
	pivot = a[low];
	j = low;
	
	for(i=low+1; i<=high; i++)
	{
		compare2++;
		if(a[i] < pivot)
		{
			j++;
			/* swap */
			swap2++;
			tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}
	pivotPos = j;
	/* swap */
	swap2++;
	tmp = a[low]; a[low] = a[pivotPos]; a[pivotPos] = tmp;
	return pivotPos;
}
