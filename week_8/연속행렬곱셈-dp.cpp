#include <stdio.h>
#include <iostream>

#define min(a,b) a < b ? a : b

using namespace std;

int **memo;
int **P;
int cmm(int len_arr, int* input);
int print_cmm(int i, int j, int* input);

int main(){
	int tc;
	cin >> tc;
	while(tc--)
	{
		
		int len_arr;
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
				memo[i][j] = 0;
			}
		}

		P = new int*[len_arr+1];
		for(int i = 0; i < len_arr+1; i++){
			P[i] = new int[len_arr+1];
			for(int j = 0; j < len_arr+1; j++){
				P[i][j] = 0;
			}
		}
		int answer = cmm(len_arr, input);
		
		print_cmm(0,len_arr-1,input);
		
		cout << endl;
		cout << answer << endl;
//		for(int i = 0; i < len_arr+1; i++){
//			for(int j = 0; j < len_arr+1; j++){
//				cout << memo[i][j] <<  " ";
//			}
//			cout << endl;
//		}
	}

	return 0;
}




int cmm(int len_arr, int* input)
{

	for(int i = 0; i <= len_arr-1 ; i++)
	{
		for(int j = 0; i+j <= len_arr; j++)
		{
			int tmp_i = j;
			int tmp_j = i + j;
			int min_count = 99999;
			if(tmp_i == tmp_j){
				continue;
			}
//			cout << i << " " <<j << " "<< tmp_i << " " << tmp_j << endl;
			for(int k = tmp_i; k < tmp_j; k++)
			{
//				cout << k <<endl;
//				if(tmp_i == 0, tmp_j == 1){
//					cout << memo[tmp_i][k] << " "<<  memo[k+1][tmp_j] << " " << input[tmp_i] << " " <<input[k+1] << " "<<input[tmp_j+1]<<endl;
//				}



				
				if(min_count >= memo[tmp_i][k] + memo[k+1][tmp_j] + input[tmp_i]*input[k+1]*input[tmp_j+1]){
					min_count = memo[tmp_i][k] + memo[k+1][tmp_j] + input[tmp_i]*input[k+1]*input[tmp_j+1];
					P[tmp_i][tmp_j] = k;
				}
				//				min_count = min(min_count, memo[tmp_i][k] + memo[k+1][tmp_j] + input[tmp_i]*input[k+1]*input[tmp_j+1]);
				
			}
			memo[tmp_i][tmp_j] = min_count;
		}		
	}
	
//	for(int i = 0; i < len_arr+1; i++)
//	{
//		for(int j = 0; j < len_arr+1; j++)
//		{
//			cout << P[i][j] << " ";
//		}
//		cout << endl;
//	}
	return memo[0][len_arr-1];
}

int print_cmm(int i, int j, int* input){
	
	if(i==j)
		cout << "M" <<i+1;
	else{
		int k = P[i][j];
		cout << "(";
		print_cmm(i,k,input);
		print_cmm(k+1, j, input);
		cout << ")";
	}
}
