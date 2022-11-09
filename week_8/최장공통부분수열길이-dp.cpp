#include <stdio.h>
#include <iostream>

#define max(a,b) a > b ? a : b

using namespace std;

int len_str1;
int len_str2;
int LCS(int m, int n);
int LCS_print(int m, int n);

int **memo;
char *str1;
char *str2;
char *answer;
int answer_idx;

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
				memo[i][j] = 0;
			}
		}

		answer_idx = 1;
//		answer = new char[9999];
//		for(int i = 0; i < 9999; i++){
//			answer[i] = 0;
//		}
		
	
		cout << LCS(len_str1-1, len_str2-1) << " ";
		answer_idx = memo[len_str1][len_str2];
		LCS_print(len_str1, len_str2);
		cout << endl;
//		for(int i = answer_idx; i >= 0; i--){
//			cout << answer[i];
//		}
//		cout << endl;
	}
	
	return 0;
}

int LCS(int m, int n){
	
	for(int i = 1; i < len_str1+1; i++){
		for(int j = 1; j < len_str2+1; j++){
			if(str1[i-1] == str2[j-1]){
				memo[i][j] = memo[i-1][j-1] + 1;
			} else {
				memo[i][j] = max(memo[i][j-1], memo[i-1][j]);	
			}
		}
	}
	
//	for(int i = 0; i < len_str1+1; i++){
//		for(int j = 0; j < len_str2+1; j++){
//			cout << memo[i][j] << " ";
//		}
//		cout << endl;
//	}

//	for(int i = 1; i < len_str1+1; i++){
//		for(int j = 1; j < len_str2+1; j++){
//			if(answer_idx == memo[i][j]){
//				answer[answer_idx-1] = str2[j-1];
//				answer_idx += 1;
//				break;
//			}
//		}
//	}

	return memo[len_str1][len_str2];
}


//int LCS_print(int m, int n){
//
//	if(m == 0 | n==0){
//		return 0;
//	}
//	
//	if(memo[m][n] == memo[m-1][n] & memo[m][n] == memo[m][n-1]){
//		LCS_print(m, n-1);
//	} else if (memo[m][n] == memo[m][n-1] ){
//		LCS_print(m, n-1);
//	} else if (memo[m][n] == memo[m-1][n] ){
//		LCS_print(m-1, n);
//	} else {
//
//		cout << "("<<m-1<<" " << str1[m-1] << ") ";
//		LCS_print(m-1, n-1);	
//	}
//	// 위 옆 둘 다 같으면 위쪽
//	//하나만 같으면 같은쪽
//	// 둘다 다르면 대각선 
//
//
//	return memo[m][n];
//}

int LCS_print(int m, int n){

	if(m == 0 | n==0){
		return 0;
	}

	
	if( str1[m-1] == str2[n-1] & memo[m][n] == answer_idx){

		answer_idx -= 1;
		
		LCS_print(m-1,n-1);
		cout << str1[m-1];
	} else if( memo[m][n-1] == memo[m][n]){
		LCS_print(m,n-1);
	} else if( memo[m-1][n] == memo[m][n] ){
		LCS_print(m-1, n);
	}
	
	

	return memo[m][n];
}
