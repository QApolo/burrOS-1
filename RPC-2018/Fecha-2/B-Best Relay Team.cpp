/*
*   User: oozmas
*   Problem: RPC 2nd Activity B-Best Relay Team
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> dd;
typedef pair<dd, string> dds;
typedef set<dds> sdds;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	sdds first;
	sdds second;

	for (int i = 0; i <  n; ++i)
	{
		double a;
		double b;
		string name;
		cin >> name >> a >> b;
		first.insert(dds(dd(a, b), name));
		second.insert(dds(dd(b, a), name));
	}

	vector<string> m;
	double minSum = 1e9;

	for (sdds::iterator i = first.begin(); i != first.end(); ++i)
	{
		int current = 1;
		vector<string> names;
		string name1 = i->second;
		names.push_back(name1);
		double s = i->first.first;
		
		for (sdds::iterator j = second.begin(); j != second.end() and current < 4; ++j)
		{
			if (j->second != name1)
			{
				++current;
				s += j->first.first;
				names.push_back(j->second);
			}
		}

		if (s < minSum)
		{
			minSum = s;
			m = names;
		}
	}

	cout << minSum << "\n";

	for (int i  = 0; i < 4; ++i)
		cout << m[i] << "\n";

	return 0;
}