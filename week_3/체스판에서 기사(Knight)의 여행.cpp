#include <stdio.h>
#include <iostream>

using namespace std;

int m, n, s, t;
bool flag;
int explore(int row, int col, int count, int **visited);
void degree(int row, int col, int **visited);
int idx_arr[8] = {0,};

int m_1[] = { 2, 1, -1, -2, -2, -1, 1, 2};
int m_2[] = { 1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	int tc;
	cin >> tc;
	
	while(tc--)
	{
		flag = false;
		cin >> m >> n >> s >> t;
		
		int** visited = new int*[m];
		for(int i=0; i<m; i++)
		{
			visited[i] = new int[n];
			for(int j=0; j<n; j++)
			{
				visited[i][j] = 0;
			}			
		}
		
		explore(s-1, t-1, 1, visited);
		if(!flag)
		{
			cout << 0 <<endl;
		}
	}	
	return 0;
}


void degree_arr(int row, int col, int **visited)
{
	int arr[8];
//	int *idx_arr = new int[8];

	// 8위치로 이동 
	for(int i = 0;  i < 8; i++)
	{
		int count = 0;
		
		int tmp_row = row + m_1[i];
		int tmp_col = col + m_2[i];
		if(tmp_row < 0 || tmp_col < 0 || tmp_row >= m || tmp_col >= n)
		{
			arr[i] = 0;
			continue;
		}
		// degree 세기 
		for(int j = 0;  j < 8; j++)
		{
			int tmp_tmp_row =  tmp_row + m_1[j];
			int tmp_tmp_col =  tmp_col + m_2[j];
			if(tmp_tmp_row < 0 || tmp_tmp_col < 0 || tmp_tmp_row >= m || tmp_tmp_col >= n)
			{
				continue;
			}
			if(visited[tmp_tmp_row][tmp_tmp_col] == 0)
			{
				count++;
			}
		}
		
		arr[i] = count;
		
	}

	// 큰 수대로 idx 정렬하기
	
	int idx = 0;
	for(int d = 0;  d < 9; d++)
	{
		for(int j = 0;  j < 8; j++)
		{
//			cout << d << j << endl;
			if(arr[j] == d)
			{
				idx_arr[idx++] = j;
			}
		}
	}

}

int explore(int row, int col, int count, int **visited)
{
	
	// 발견했으면 true 
	if (flag == true)
	{
		return 0;
	}
	
	// 예외처리 
	if(row < 0 || col < 0 || row >= m || col >= n)
	{
		return 0;
	}
	
	// 방문처리 
	if(visited[row][col] == 0)
	{
		visited[row][col] = count;	
	} else {
		return 0;
	}
	
		
	if(count >= m*n)
	{
		// 경로 출력
		cout << 1 << endl;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}

		flag = true;
		
		return 0;
	}
	
	degree_arr(row, col, visited);
	
	for(int i = 0;  i < 8; i++)
	{
		explore(row+m_1[idx_arr[i]], col+m_2[idx_arr[i]], count+1, visited);
	}
	
	visited[row][col] = 0;
	
	return 0;
}
