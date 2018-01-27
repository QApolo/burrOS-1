/*
*   User: burrOS
*   Problem: RPC 1st Activity G-Grid
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int m;
int n;

inline bool isValid(int x, int y) { return x < m and x > -1 and y < n and y > -1; }

int main(void)
{
	const int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	int grid[m][n];
	
	for (int i = 0; i < m; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < n; ++j)
			grid[i][j] = (int)line[j] - '0';
	}

	int level[m][n];
	queue<ii> node;
	memset(level, (int)1e6, sizeof level);
	
	level[0][0] = 0;
	node.push(ii(0, 0));
	
	while (not node.empty())
	{
		ii current = node.front();
		node.pop();
		int k = grid[current.first][current.second];
		for (int i = 0; i < 4; ++i)
		{
			int x = current.first + moves[i][0] * k;
			int y = current.second + moves[i][1] * k;

			if (isValid(x, y) and level[x][y] > level[current.first][current.second] + 1)
			{
				level[x][y] = level[current.first][current.second] + 1;
				if (x == m - 1 and y == n - 1)
					break;
				node.push(ii(x, y));
			}
		}
	}

	if (level[m - 1][n - 1] >= (int)1e6)
		cout << "IMPOSSIBLE\n";
	else
		cout << level[m - 1][n - 1] << "\n";

	return 0;
}