#include <iostream>
#include <stdio.h>

using namespace std;

long **board;
long N;
long count;
long *answer_arr;

long minus_1(long y, long x);
long plus_1(long y, long x);
long explore(long y, long x);

int main()
{
	long tc;
	cin >> tc;
	
	while(tc--)
	{
		
		cin >> N;
		count = 0;
		answer_arr = new long[N];
		board = new long*[N];
		for(long i =0; i<N; i++){
			board[i] = new long[N];
			for(long j =0; j<N; j++){
				board[i][j] = 0;
			}					
		}
		
		explore(0,0);	
		for(long i =0; i<N; i++){
			cout << answer_arr[i] << " ";
		}
		cout << endl;
		
	}
	return 0;
}

long explore(long y, long x)
{
	
	if(count >= N){	
		count += 1;
		return 0;
	}
	
	
//	cout << count << endl;
//	for(long i =0; i<N;i++){
//		for(long j =0; j<N;j++){
//			cout << board[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	
	// 이동  
	for(long j =0; j<N; j++){
		long next_y = y;
		long next_x = j;
		// 놓을 수 있는 곳이면  
		if(board[next_y][next_x] == 0){
			long tmp = answer_arr[next_y];
			answer_arr[next_y] = next_x+1;
			plus_1(next_y, next_x);
			explore(next_y+1, next_x);
			if(count >= N){	
				return 0;
			}
			minus_1(next_y, next_x);
			answer_arr[next_y] = tmp;
		}		
	}
							
}



long plus_1(long y, long x){
	count += 1;
	long i;
	// 놓을 수 없는곳 +1
	for(long i =0; i<N; i++){
		board[y][i] += 1;
	} 
	for(long i =0; i<N; i++){
		board[i][x] += 1;
	}
	i = 0;
	while( x+i>=0 & y+i>=0 & x+i<N & y+i<N){
		board[y+i][x+i] += 1;
		i += 1;
	}
	i = 0;
	while( x-i>=0 & y+i>=0 & x-i<N & y+i<N){
		board[y+i][x-i] += 1;
		i += 1;
	}
	i = 0;
	while( x+i>=0 & y-i>=0 & x+i<N & y-i<N){
		board[y-i][x+i] += 1;
		i += 1;
	}
	i = 0;
	while( x-i>=0 & y-i>=0 & x-i<N & y-i<N){
		board[y-i][x-i] += 1;
		i += 1;
	}
	return 0;	
} 

long minus_1(long y, long x){
	count -= 1;
	long i;
	// 놓을 수 없는곳 +1
	for(long i =0; i<N; i++){
		board[y][i] -= 1;
	} 
	for(long i =0; i<N; i++){
		board[i][x] -= 1;
	}
	i = 0;
	while( x+i>=0 & y+i>=0 & x+i<N & y+i<N){
		board[y+i][x+i] -= 1;
		i += 1;
	}
	i = 0;
	while( x-i>=0 & y+i>=0 & x-i<N & y+i<N){
		board[y+i][x-i] -= 1;
		i += 1;
	}
	i = 0;
	while( x+i>=0 & y-i>=0 & x+i<N & y-i<N){
		board[y-i][x+i] -= 1;
		i += 1;
	}
	i = 0;
	while( x-i>=0 & y-i>=0 & x-i<N & y-i<N){
		board[y-i][x-i] -= 1;
		i += 1;
	}
	return 0;
} 
