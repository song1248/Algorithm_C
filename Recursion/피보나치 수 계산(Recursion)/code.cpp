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
		printf("%d\n", recursion(test_n));
		
		}
	return 0;
}

long recursion(int n)
{
	if(n == 0)
	{
		return 0;
	} else if(n == 1) {
		return 1;
	} else{
		return recursion(n-1) + recursion(n-2);
	}

}
