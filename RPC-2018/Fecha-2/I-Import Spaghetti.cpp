/*
*   User: oozmas
*   Problem: RPC 2nd Activity I-Import Spaghetti
*/
#include <bits/stdc++.h>

#define MAX 1e9

using namespace std;

int cnt = 0;
vector<string> p;
map<int, string> nm;
map<string, int> id;
vector< vector<int> > parent(500, vector<int>(500));

void path(int i, int j)
{
	if (parent[i][j] != i)
		path(i, parent[i][j]);

	p.push_back(nm[parent[i][j]]);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		nm[i] = name;
		id[name] = i;
	}
	
	vector< vector<int> > dist(n, vector<int>(n, MAX));

	for (int i = 0; i < n; ++i)
	{
		int t;
		string name;
		cin >> name >> t;

		while (t--)
		{
			string import;
			cin >> import;
			getline(cin, import);

			istringstream in(import);

			while (in >> import)
			{
				if (import[import.length() - 1] == ',')
					import.pop_back();

				dist[id[name]][id[import]] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			parent[i][j] = i;
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					parent[i][j] = parent[k][j];
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int u = -1;
	int minC = MAX;

	for (int i = 0; i < n; ++i)
	{
		if (dist[i][i] < minC)
		{
			u = i;
			minC = dist[i][i];
		}
	}

	if (u == -1 or minC >= MAX)
		cout << "SHIP IT\n";
	else
	{
		path(u, u);

		for (int i = 0; i < p.size(); ++i)
			cout << p[i] << (i + 1 == p.size()?"\n":" ");
	}

	return 0;
}