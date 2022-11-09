#include <stdio.h>
#include <iostream>

#define min(a,b) a < b ? a : b

using namespace std;

int M(int s_idx, int e_idx, int* input);

int main(){
	
	int tc = 0;
	cin >> tc;
	
	
	while(tc--)
	{
		int input_size;
		cin >> input_size;
		int* input = new int[input_size+1];
		for(int i = 0; i<input_size+1 ;i++)
		{
			int num;
			cin >> num;
			input[i] = num;
		}
	
		cout << M(0, input_size,  input) << endl;
	}
	
	return 0;
}


//1 2 3 4 5

int M(int s_idx, int e_idx, int* input)
{
	 if (e_idx - s_idx < 2){
	 	return 0;
	 }
	 
	 if (e_idx - s_idx == 2){
	 	return input[s_idx] * input[s_idx+1] * input[e_idx];
	 }
	 	
	int tmp_min_count = 99999;
	// 시작과 끝사이의 모든조합 탐색  
	for(int mid = s_idx+1; mid < e_idx; mid++)
	{
		int tmp_count = M(s_idx, mid, input) + M(mid, e_idx, input) + input[s_idx] * input[mid] * input[e_idx];
		tmp_min_count = min(tmp_min_count, tmp_count);
//		cout <<  s_idx << " " << mid <<" " << e_idx << " "<<tmp_count << endl;
	}
	
	return tmp_min_count;
}
