//스트링 뒤집기(Recursion)
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using namespace std;

string recursion(string str, int s, int e);
 
int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i)
		{
		string test_s;

		cin >> test_s;
		
		cout << recursion(test_s, 0, test_s.length()-1) <<endl;
		
		}
	return 0;
}

string recursion(string str, int s, int e)
{
	if (s >= e){
		return str;
	}
	
	char tmp = str[s];
	str[s] = str[e]; 
	str[e] = tmp;
		
	return recursion(str, s+1, e-1);
