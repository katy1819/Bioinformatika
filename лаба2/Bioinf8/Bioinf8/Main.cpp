#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int v[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186};
	int n;
	long long int n1;
	cin >> n;
	map<int, long long int> N;
	N[0] = 1;

	for (int i = 57; i < n + 1; i++)
	{
		N[i] = 0;
		for (int j = 0; j < 18; j++)
			if (N[i - v[j]])
				N[i] += N[i - v[j]];
	}
	n1 = N[n];
	cout << n1;
}