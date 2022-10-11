#include <stdio.h>
#include <iostream>

#define MAX_SIZE 100

using namespace std;
int count;
void merge_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);


int main(){
	int tc;
	cin >> tc;
	while(tc--)
	{
		int len_arr;
		cin >> len_arr;
		int *arr = new int[len_arr];
		
		for(int i = 0; i < len_arr;i++)
		{
			int num;
			cin >> num;
			arr[i] = num;	
		}
		
		count = 0;
		
		merge_sort(arr, 0 ,len_arr-1);
		cout << count << endl;
	
	}
	
	return 0;
}

void merge_sort(int a[], int low, int high)
{
	
	// 반으로 나누고
	
	int mid;
	if(low >= high)
		return;
	
	mid = (high + low)/2;
	
	//왼쪽 정렬
	merge_sort(a, low, mid);
	//오른쪽 정렬
	merge_sort(a, mid+1, high);
	//합치기
	merge(a, low, mid, high); 
	
}

void merge(int a[], int low, int mid, int high)
{
 int i, j, k;
 int tmp[MAX_SIZE];
 for(i=low; i<=high; i++)
 	tmp[i] = a[i];
 i = k = low;
 j = mid+1;
 while(i<=mid && j<=high)
 {
 	count += 1;
	 if(tmp[i] <= tmp[j]) // <---- 핵심연산자(비교연산자)
	 {
	 	a[k++] = tmp[i++];
	 } else {
	 	a[k++] = tmp[j++];
	 }
	 		
 }
 while(i<=mid)
 	a[k++] = tmp[i++];
 while(j<=high)
 	a[k++] = tmp[j++];
}
