#include <stdio.h>
#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);
int main()
{
 int numTestCases;
 int a[MAX_SIZE], b[MAX_SIZE];
 scanf("%d", &numTestCases);
 for (int i = 0; i < numTestCases; ++i)
 {
	 int num;
	 scanf("%d", &num);
	 for (int j = 0; j < num; j++)
	 	scanf("%d", &b[j]);
	 	
	 copyArray(a, b, num);
	 bubbleSort(a, num);
	 
	 copyArray(a, b, num);
	 bubbleSortImproved1(a, num);
	 
	 copyArray(a, b, num);
	 bubbleSortImproved2(a, num);
	 printf("\n");
 }
 return 0;
}
void swap(int* a, int* b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort 알고리즘 구현
 for(int pass = 1; pass < n; pass++){
 	for(int i = 1; i <= n - pass; i++)
 	{
 		countCmpOps += 1;
 		if(a[i-1] > a[i])
		{
			swap(&a[i-1], &a[i]);
			countSwaps += 1;	
		}	
	}
 } 
 
 printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort의 개선된 알고리즘 (1) 구현
 for(int pass = 1; pass < n; pass++){
 	bool swapped = false;
 	for(int i = 1; i <= n - pass; i++)
 	{
 		countCmpOps += 1;
 		if(a[i-1] > a[i])
		{
			swap(&a[i-1], &a[i]);
			swapped = true;
			countSwaps += 1;	
		}
	 	if(swapped == false)
	 		break;
	}
 } 
 printf("%d %d ", countCmpOps, countSwaps);
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 int lastSwappedPos = n;
 // bubble sort의 개선된 알고리즘 (2) 구현
 while(lastSwappedPos > 0){
 	// 안바뀌면 0 바뀌면 1~n 
 	int swappedPos = 0;
 	for(int i = 1; i < lastSwappedPos; i++)
 	{
 		countCmpOps += 1;
 		if(a[i-1] > a[i])
		{
			swap(&a[i-1], &a[i]);
			swappedPos = i;
			countSwaps += 1;	
		}
	 	
	}
	lastSwappedPos = swappedPos;
 }
 printf("%d %d ", countCmpOps, countSwaps);
}
void copyArray(int a[], int b[], int n)
{
 for (int i = 0; i < n; i++)
 	a[i] = b[i];
}
