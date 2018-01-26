/*
*   User: burrOS
*   Problem: RPC 1st Activity A-Blur 
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int blur;
	int width;
	int height;
	cin >> width >> height >> blur;

	vector< vector<int> > grid(height + 2, vector<int>(width + 2));

	for(int i = 1; i <= height; ++i)
	{
		for(int j = 1; j <= width; ++j)
			cin >> grid[i][j];
	}

	/* Neighbors in the corners. */
	grid[0][0] = grid[height][	width];
	grid[0][width + 1] = grid[height][1];
	grid[height + 1][0] = grid[1][width];
	grid[height + 1][width + 1] = grid[1][1];
	/* Neighbors around. */
	for(int j = 1; j <= width; ++j)
	{
		grid[0][j] = grid[height][j];
		grid[height + 1][j] = grid[1][j];
	}
	/* Neighbors around. */
	for(int i = 1; i <= height; ++i)
	{
		grid[i][0] = grid[i][width];
		grid[i][width + 1] = grid[i][1];
	}

	set<int> values;
	/* Simulation blur-times. */
	for(int r = 0; r < blur; ++r)
	{
		vector< vector<int> > backup = grid;
		/* Simulation of blur. */	
		for(int i = 1; i <= height; ++i)
		{

			for(int j = 1; j <= width; ++j)
			{
				int sum = 0;
				/* Sum of the neighbors' value without denominator. */	
				for(int k = i - 1; k <= i + 1; ++k)
				{
					for(int l = j -1; l <= j + 1; ++l)
						sum += backup[k][l];
				}
				/* If It is last simulation then insert value of current cell. */
				if(r + 1 == blur)
					values.insert(sum);
				/* Update cell value. */
				grid[i][j] = sum;
			}
		}
		/* Update corners and neighbors around. */
		grid[0][0] = grid[height][width];
		grid[0][width + 1] = grid[height][1];
		grid[height + 1][0] = grid[1][width];
		grid[height + 1][width + 1] = grid[1][1];

		for(int j = 1; j <= width; ++j)
		{
			grid[0][j] = grid[height][j];
			grid[height + 1][j] = grid[1][j];
		}

		for(int i = 1; i <= height; ++i)
		{
			grid[i][0] = grid[i][width];
			grid[i][width + 1] = grid[i][1];
		}
	}

	/* Size of the set that stores unique values of the simulation. */
	cout << values.size() << endl;

	return 0;
}