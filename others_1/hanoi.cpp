#include <stdio.h>
#include <iostream>

using namespace std;

int explore(int *dp, int n);

int explore(int n, int s, int t, int e);
int top = -1;
int* stack;

int main()
{
	int testcase;
	cin >> testcase;
	
	while(testcase--)
	{
		int layer;
		cin >> layer;
		stack = new int[layer];
		int tmp = layer;
		while(tmp--)
		{
			stack[tmp] = 0;	
		}
		
		explore(layer, 1 , 2 , 3 );	
		cout << endl;
	}
	
	
	return 0;
}

//# 맨 왼쪽에 있는것을 옮기려면 
int explore(int n, int s, int t, int e)
{
	if(n==0)
	{
		return 0;
	}

//	# 위에있는것을 가운대
	explore(n-1, s, e, t);
//	# 맨아래거 옮기기
	if(e == 3)
	{
		cout << n << " ";
		stack[++top] = n;	
	}
	if( s == 3)
	{
		top--;
		if(top == -1){
			cout << "0 ";
		} else {
			cout << stack[top] << " ";	
		}
				
	}
//	# 가움대 있는것을 맨 오른쪽
	explore(n-1, t, s, e);
	 
	
}
