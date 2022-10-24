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

//# �� ���ʿ� �ִ°��� �ű���� 
int explore(int n, int s, int t, int e)
{
	if(n==0)
	{
		return 0;
	}

//	# �����ִ°��� �����
	explore(n-1, s, e, t);
//	# �ǾƷ��� �ű��
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
//	# ����� �ִ°��� �� ������
	explore(n-1, t, s, e);
	 
	
}
