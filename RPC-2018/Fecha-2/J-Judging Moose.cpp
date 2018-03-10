/*
*   User: oozmas
*   Problem: RPC 2nd Activity J-Judging Moose
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int l;
	int r;
	cin >> l >> r;
	if (not l and not r)
		cout << "Not a moose\n";
	else if (l == r)
		cout << "Even " << l + r << "\n";
	else if(l > r)
		cout << "Odd " << l + l << "\n";
	else
		cout << "Odd " << r + r << "\n";
	return 0;
}