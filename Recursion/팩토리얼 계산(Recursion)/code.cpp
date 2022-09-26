#include <stdio.h>

long recursion(int n);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i)
		{
		int test_n;
		scanf("%d", &test_n);
		printf("%d\n", recursion(test_n)%1000);
		
		}
	return 0;
}

long recursion(int n)
{
	if(n == 0)
	{
		return 1;
	}
	
	int tmp = n * recursion(n-1);
	while (tmp % 10 == 0)
	{

		tmp /= 10;
	}
	
	return tmp % 100000;
}
