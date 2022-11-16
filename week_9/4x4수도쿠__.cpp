#include <iostream>
#include <stdio.h>
#define N 4

using namespace std;

bool isSafe(int **grid, int row, int col, int num)
{

    for (int x = 0; x <= 3; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 3; x++)
        if (grid[x][col] == num)
            return false;
 
    int startRow = row - row % 2;
	int startCol = col - col % 2;
   
    for (int i = startRow; i < startRow + 2; i++)
        for (int j = startCol; j < startCol + 2; j++)
            if (grid[i][j] == num)
                return false;
 
    return true;
}

bool explore(int  **grid, int row, int col)
{

    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return explore(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {   
            grid[row][col] = num;         
            if (explore(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}


int main(){
	
	int tc;
	cin >> tc;
	while(tc--){
		
		int **grid = new int*[4] ;
		for(int i=0;i<4;i++){
			grid[i] = new int[4];
			for(int j=0;j<4;j++){
				int num;
				cin >> num;
				grid[i][j] = num;
			}
		}
		
		explore(grid, 0, 0);
		
	    for (int i = 0; i < N; i++)
	    {
	        for (int j = 0; j < N; j++)
	            cout << grid[i][j] << " ";
	        cout << endl;
	    }
	}

	return 0;
}

