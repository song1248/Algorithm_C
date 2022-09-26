#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int permutations(string str, int i, int n, int w_value);
int str_len;

int main()
{
	int testcase;
	cin >> testcase;
	
	for (int tc = 0; tc < testcase; tc++ )
	{
		string str;
		cin >> str;
		str_len = str.length();
		cout << permutations(str, 0, str.length(), 0) << endl;
	}
	
	return 0;
}

int permutations(string str, int i, int n, int w_value)
{
	
	int sum = 0;
	
	if(i > 0){
	 	if ((i-1)%2 == 0)
	    {
	    	w_value += int(str[i-1] - int('a'));
		} else {
			w_value -= int(str[i-1] - int('a'));
		}		
	}


		
    // 기본 조건
    if (i == n)
    {
//    	cout << str << " : " << w_value << endl;
		if(w_value > 0)
		{
			return 1; 
		} else {
			return 0;
		}
    }
 
    // 나머지 문자열의 각 문자 처리
    for (int j = i; j < n; j++)
    {
        swap(str[i], str[j]);

        sum += permutations(str, i + 1, n, w_value);
 
        swap(str[i], str[j]);
    }
	
	return sum;
}
