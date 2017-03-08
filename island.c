#include <stdio.h>
#include <string.h>
#define row 5
#define col 5

int isSafe(int M[row][col], int i, int j, int visited[row][col])
{
  return ((i>=0) && (j>=0) && (i<row) && (j<col) && M[i][j] && !visited[i][j]);
}

void DFS(int M[row][col], int i, int j, int visited [row] [col])
{
  int rowI[8] = {-1,-1,-1, 0,0, 1,1,1};
  int colI[8] = {-1, 0, 1,-1,1,-1,0,1};
  visited[i][j] = 1;
  for (int k = 0;k<8;k++)
  {
	  if(isSafe(M, i+rowI[k],j+colI[k],visited))
	  {
		  DFS(M,i+rowI[k],j+colI[k],visited);
	  }

  }
}


int noOfIslands(int M[row][col])
{
	int count = 0, i, j;
	int visited [row][col];
	memset(visited,0,row*col*sizeof(int));

	for (i = 0; i< row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (M[i][j] == 1)
			{
				if( !visited[i][j])
				{
					DFS(M,i, j, visited);
					count++;
				}
			}
		}
	}
	return count;

}

void main()
{
	int M[row][col] = { {1,0,0,1,1},
						{0,1,0,1,0},
						{1,0,0,1,1},
						{0,1,0,0,0},
						{1,0,0,1,1}
	};

	printf("No Of Islands: %d\n",noOfIslands(M));
}
