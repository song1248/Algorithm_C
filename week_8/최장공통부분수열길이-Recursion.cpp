#include <stdio.h>
#include <iostream>

#define max(a,b) a > b ? a : b

using namespace std;

int len_str1;
int len_str2;
int LCS(int m, int n);
char *str1 = new char[10];
char *str2 = new char[10];

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		str1 = new char[10];
		str2 = new char[10];
		len_str1 = 0;
		len_str2 = 0;
		cin >> str1;
		cin >> str2;
		
		
		for(int i = 0; i < 10; i++){
			if (str1[i]){
				len_str1++;
			}
		}
		for(int i = 0; i < 10; i++){
			if (str2[i]){
				len_str2++;
			}
		}
		
		cout << LCS(len_str1-1, len_str2-1) << endl;
	
	}
	

	return 0;
}

int LCS(int m, int n){
	
	if(m<0 | n<0){
		return 0;
	} else if( m >= 0 & n >= 0 & str1[m] == str2[n] ){
		return LCS(m-1, n-1) + 1;
	} else if ( m >= 0 & n >= 0 & str1[m] != str2[n] ){
		int a = LCS(m-1, n);
		int b = LCS(m, n-1);
		return max(a,b);
	}
	return 0;
}
