#include <stdio.h>
#include <iostream>

using namespace std;
struct stack {

	int arr[10000];
	int last;

	void init() {
		last = -1;
	}
	void push(int data) {
		arr[++last] = data;
		cout << data << " ";
	}
	bool empty() {
		return (last < 0);
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		cout << arr[last-1] << " ";
		return arr[last--];
	}
	int size() {
		return last + 1;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return arr[last];
	}
};

stack s;
void recursive(int layer, int start, int other, int big);

int main()
{
	int testcase;
	cin >> testcase;
	
	for (int tc = 0; tc < testcase; tc++ )
	{
		int layer;
		cin >> layer;
		
		s.init(); 
			
		recursive(layer, 1 , 2 , 3 );	
		cout << endl;
	}
	
	
	return 0;
}


void recursive(int layer, int start, int other, int big)
{

	if (layer>0)
	{
		
		// 위에거 옮기고  
		recursive(layer-1, start, big, other);			
		// 맨아래거 옮기고
//		cout << layer << start << other << big << endl;
		if (big == 3)
		{
			s.push(layer);
		} else if(start == 3) {
			s.pop();
		}
		
		// 옮겼던거 다시 옯기고 
		recursive(layer-1, other, start, big);
	
	}
	
}
