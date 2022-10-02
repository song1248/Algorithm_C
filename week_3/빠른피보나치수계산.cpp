#include <stdio.h>
#include <iostream>


using namespace std;

long **square_matrix(long **arr_1, long **arr_2);
long fibonacci(long **arr, long n);

int main()
{
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		
		long** arr = new long*[2];
		for(int i=0; i<2; i++)
		{
			arr[i] = new long[2];
			for(int j=0; j<2; j++)
			{
				arr[i][j] = 1;
			}			
		}
		arr[1][1] = 0;
		
		long n;
		cin >> n; 
		
		cout << fibonacci(arr, n) << endl;
	}
	
	return 0;
}

  
 
long **square_matrix(long **arr_1, long **arr_2)
{
	long** arr = new long*[2];
	for(int i=0; i<2; i++)
	{
		arr[i] = new long[2];
		for(int j=0; j<2; j++)
		{
			arr[i][j] = 0;
		}			
	}
	
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                arr[i][j] += arr_1[i][k] * arr_2[k][j];
            }
            arr[i][j] %= 1000;
        }
    }

	return arr;
}



long fibonacci(long **arr, long n)
{	
	long** ans = new long*[2];
	for(int i=0; i<2; i++)
	{
		ans[i] = new long[2];
		for(int j=0; j<2; j++)
		{
			ans[i][j] = 0;
		}			
	}
	
	ans[0][0] = 1;
	ans[1][1] = 1;


    while (n > 0) 
	{
		if (n % 2 == 1) {
        	ans = square_matrix(ans, arr);
    	}
        arr = square_matrix(arr, arr);
        n /= 2;
    }

    return ans[0][1];
		
}


