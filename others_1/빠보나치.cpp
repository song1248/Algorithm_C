#include <iostream>
#include <stdio.h>

using namespace std;


int **basic = new int*[2];
int **i_matirx = new int*[2];

		
int** BBAbonacci(int n, int **arr);
int** matrix_product(int** a, int** b);

int main()
{
	for(int i = 0; i<2; i++)
	{
		i_matirx[i] = new int[2];
	}
	i_matirx[0][0] = 1;
	i_matirx[0][1] = 0;
	i_matirx[1][0] = 0;
	i_matirx[1][1] = 1;
	int testcase;
	cin >> testcase;
	for(int i = 0; i<2; i++)
	{
		basic[i] = new int[2];
	}
	basic[0][0] = 1;
	basic[0][1] = 1;
	basic[1][0] = 1;
	basic[1][1] = 0;
	
	while(testcase--)
	{


		
		int num;
		cin >> num;
		
		int** tmp = BBAbonacci(num, basic);
		for(int i = 0; i<2; i++)
		{
			for(int j = 0; j<2; j++)
			{
				cout << tmp[i][j] << " ";	
			}
		}		
		cout << endl;
//		cout << tmp[0][1] << endl;
		
	}
	
	
	return 0;
}

int** BBAbonacci(int n, int **arr)
{
	int **ans;
	
	if(n == 0)
	{
		return i_matirx;
	}
	
	if (n % 2 == 0)
	{
		int **tmp = BBAbonacci(n/2, arr);
		ans = matrix_product(tmp, tmp);
	} else {
		int **tmp = BBAbonacci(n/2, arr);
		ans = matrix_product(tmp, tmp);
		ans = matrix_product(ans, basic);
	}
	
	return (int**)ans;
}

int** matrix_product(int** a, int** b)
{

	int **matrix = new int*[2];
	for(int i = 0; i<2; i++)
	{
		matrix[i] = new int[2];
		for(int j = 0; j<2; j++)
		{
			for(int k = 0; k<2; k++)
			{
				matrix[i][j] += a[i][k]*b[k][j];
			}			
		}		
	}

	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<2; j++)
		{
			matrix[i][j] %= 1000;			
		}		
	}	
	
	return(int**) matrix;
}
