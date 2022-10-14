#include <stdio.h>
#include <iostream>

#define MAX_SIZE 10000
#define MIN(a,b) ((a) < (b) ? (a) : (b))
 
using namespace std;

int compare;
void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int n);

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
		compare = 0;
		mergeSort(arr, arr_len);
		cout << compare << endl;
	}
	return 0;
}

void mergeSort(int v[], int n)
{
int size = 1;
while(size < n)
{
for(int i=0; i<n; i+=2*size)
{
	int low = i;
	int mid = MIN(low+size-1, n-1); //범위벗어나지않게
	int high = MIN(i+2*size-1, n-1); //범위벗어나지않게
	merge(v, low, mid, high);
	}
		size *= 2;
	}
}



void merge(int a[], int low, int mid, int high)
{
	int i, j, k;
	int tmp[MAX_SIZE];
	for(i=low; i<=high; i++)
		tmp[i] = a[i];
	i= k = low;
	j = mid+1;
	while(i<=mid & j<=high)
	{
		compare++;
		if(tmp[i] <= tmp[j])
			a[k++] = tmp[i++];
		else
			a[k++] = tmp[j++];	
	}
	
	while(i<=mid)
		a[k++] = tmp[i++];
	while(j<=high)
		a[k++] = tmp[j++];
}
