#include <stdio.h>
#include <iostream>

#define min(a,b) a < b ? a : b

using namespace std;

int **memo;
int cmm(int i, int j, int*input);
int len_arr;
int* input;

int main(){
	int tc;
	cin >> tc;
	while(tc--)
	{
		
		
		cin >> len_arr;
		int* input = new int[len_arr+1];
		for(int i = 0; i<len_arr+1;i++)
		{
			int num;
			cin >> num;
			input[i] = num;
		}
		

		memo = new int*[len_arr+1];
		for(int i = 0; i < len_arr+1; i++){
			memo[i] = new int[len_arr+1];
			for(int j = 0; j < len_arr+1; j++){
				if (i == j)
				{
					memo[i][j] = 0;
				} else {
					memo[i][j] = -1;
				}
			
			}
		}
		
//		for(int as =0; as < len_arr+1; as++){
//			cout << input[as] << " ";
//		}
//		cout << endl;
		cout << cmm(1, len_arr, input) << endl;
		
		for(int i = 0; i < len_arr; i++){
			for(int j = 0; j < len_arr; j++){
				cout << memo[i][j] << " ";
			}
			cout << endl;
		}

		
	}

	return 0;
}




int cmm(int i, int j , int * input)
{
	
	
		
	if (i == j | i < 0 | j < 0 | i > len_arr| j > len_arr){
		return 0;
	}
	
	cout << i << " " << j <<  memo[i][j]<< endl;
	cout << 1 << endl;
	if (memo[i][j] != -1){
		return memo[i][j];
	}
	cout << 2 << endl;
	int min_count = 99999;
	for(int k = i ; k < j; k++)
	{
		int a =cmm(i, k, input);
		int b = cmm(k+1, j, input);
		cout << 3 << endl;
		for(int as =0; as < len_arr+1; as++){
			cout << input[as] << endl;
		}
		cout <<"asd" << input[0] << endl;
		cout << "Asd"<<input[k]<< endl;
		cout <<"asd" <<input[j]<< endl;
		min_count = min(min_count, a + b + input[i-1]*input[k]*input[j]);
		cout << 4 << endl;
	}
	cout <<5 << endl;
	memo[i][j] = min_count;
	cout <<6 << endl;
	return memo[i][j];
}
