#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Perebor(vector<string> v1)
{
	string s = "ACGT";
	vector<string> res, v11;
	v11 = v1;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			res.push_back(v1[j] + s[i]);
		}
		v1 = v11;
	}
	return res;
}

int ChisloMut(string v2, string v)
{
	int d = 0;
	for (int i = 0; i < v.length(); i++)
	{
		if (v[i] != v2[i])
			d++;
	}
	return d;
}

int Rast(string v2, string v)
{
	int n = v2.length(), p, d, min;
	string s;
	for (int i = 0; i < v.length(); i++)
	{
		s = "";
		p = 0;
		while ((p < n) && (i < v.length()))
		{
			s += v[i];
			p++;
			i++;
		}
		if (s.length() != n)
			break;
		if ((i - n) == 0)
		{
			d = ChisloMut(v2, s);
			min = d;
		}
		else
		{
			d = ChisloMut(v2, s);
			if (d < min)
				min = d;
		}
		i = i - n;
	}
	return min;
}

int SumRast(string v2, vector<string> v)
{
	int sum, res = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum = Rast(v2, v[i]);
		res += sum;
	}
	return res;
}

vector<string> Min(vector<string> v2, vector<int> chis)
{
	vector<string> res;
	int min = chis[0], j;
	for (int i = 0; i < chis.size(); i++)
	{
		if (min > chis[i])
		{
			min = chis[i];
		}
	}
	for (int i = 0; i < chis.size(); i++)
	{
		if (min == chis[i])
			res.push_back(v2[i]);
	}

	return res;
}

int main()
{
	int k;
	vector<string> v, v1, v2, res;
	vector<int> chis;
	string s1;
	cin >> k;

	while (!cin.eof())
	{
		cin >> s1;
		v.push_back(s1);
	}

	v1.push_back("A");
	v1.push_back("C");
	v1.push_back("G");
	v1.push_back("T");

	int j = 1;
	while (j < k)
	{
		v2 = Perebor(v1);
		v1 = v2;
		j++;
	}

	for (int i = 0; i < v2.size(); i++)
	{
		chis.push_back(SumRast(v2[i], v));
	}

	res = Min(v2, chis);

	cout << res[0];

	return 0;
}