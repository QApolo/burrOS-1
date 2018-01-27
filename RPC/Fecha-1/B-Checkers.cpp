/*
*   User: burrOS
*   Problem: RPC 1st Activity B-Checkers
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int xS;
int yS;
bool endChips;
char board[30][30];
set<string> winningChips;
bool visited[30][30][450];
const int dxEat[] = {1, 1, -1, -1};
const int dyEat[] = {1, -1, 1, -1};
const int dxMove[] = {2, 2, -2, -2};
const int dyMove[] = {2, -2, 2, -2};

inline char xFormart(int x) { return x + 'a'; }

inline string yFormat(int y)
{
	stringstream ss;
	ss << y;
	
	return ss.str();
}

inline bool isValid(int x, int y) { return x < n and x >= 0 and y < n and y >= 0; }

inline void searchPath(int x, int y, int white)
{
	if(endChips)
		return;

	visited[x][y][white] = true;

	if(not white)
	{
		endChips = true;
		winningChips.insert(xFormart(xS) + yFormat(n - yS));
		
		return;
	}

	for(int i = 0; i < 4; ++i)
	{
		int xMove = x + dxMove[i];
		int yMove = y + dyMove[i];

		int xEat = x + dxEat[i];
		int yEat = y + dyEat[i];
		
		if(isValid(xMove, yMove) and board[xEat][yEat] == 'W' and board[xMove][yMove] == '_' and not visited[xMove][yMove][white - 1])
		{
			board[x][y] = '_';
			board[xEat][yEat] = '_';
			board[xMove][yMove] = 'B';
			
			searchPath(xMove, yMove, white - 1);
			
			board[x][y] = 'B';
			board[xEat][yEat] = 'W';
			board[xMove][yMove] = '_';
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int white = 0;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> board[i];
		for(int j = 0; j < n; ++j)
		{
			if(board[i][j] == 'W')
				++white;
		}
	}


	for(int i = 0; i < n and winningChips.size() < 2; ++i)
	{
		for(int j = 0; j < n and winningChips.size() < 2; ++j)
		{
			if(board[i][j] == 'B')
			{
				xS = j;
				yS = i;
				endChips = false;
				memset(visited, false, sizeof visited);

				searchPath(i, j, white);
			}
		}
	}

	if(not winningChips.size())
		cout << "None\n";
	else if(winningChips.size() > 1)
		cout << "Multiple\n";
	else
		cout << *(winningChips.begin()) << '\n';

	return 0;
}