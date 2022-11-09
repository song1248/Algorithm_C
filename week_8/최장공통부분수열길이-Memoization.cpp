#include <stdio.h>
#include <iostream>

#define max(a,b) a > b ? a : b

using namespace std;

int len_str1;
int len_str2;
int LCS(int m, int n);


int **memo;
char *str1;
char *str2;


int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		str1 = new char[10000];
		str2 = new char[10000];
		for(int i = 0; i < 10000; i++){
			str1[i] = 0;
			str2[i] = 0;
		}

		len_str1 = 0;
		len_str2 = 0;
		cin >> str1;
		cin >> str2;
			
		for(int i = 0; i < 10000; i++){
			if (str1[i]){
				len_str1++;
			} 
			if (str2[i]){
				len_str2++;
			}
		}



		memo = new int*[len_str1+1];
		for(int i = 0; i < len_str1+1; i++){
			memo[i] = new int[len_str2+1];
			for(int j = 0; j < len_str2+1; j++){
				if(i == 0 | j == 0)
				{
					memo[i][j] = 0;
				} else{
					memo[i][j] = -1;
				}
				
			}
		}
	
		cout << LCS(len_str1, len_str2) << endl;
	
	
	
//		for(int i = 0; i < len_str1+1; i++){
//			for(int j = 0; j < len_str2+1; j++){
//				cout << memo[i][j] << " ";
//			}
//			cout << endl;
//		}
	}
	
	return 0;
}

int LCS(int m, int n){
	



//	cout << m << " asd" << n << endl;
	if(m == 0 | n==0){
		return 0;
	}
	if (memo[m][n] != -1)
	{
		return memo[m][n];
	}
	
//	for(int i = 1; i < len_str1+1; i++){
//		for(int j = 1; j < len_str2+1; j++){
			if(str1[m-1] == str2[n-1]){
				memo[m][n] = LCS(m-1, n-1) + 1;
			} else {
				memo[m][n] = max( LCS(m, n-1), LCS(m-1, n));	
			}
//		}
//	}

	return memo[m][n];
}
