#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Mut(string s5, int d)
{
	string s, s1 = "ACTG";
	int p = 0, j = 0, i = 0;
	vector<string> mut;
	s = s5;
	string ss = s5;
	mut.push_back(s5);
	while (i < s.length())
	{
		ss = s5;
		while (j < s1.length())
		{

			if (s[i] != s1[j])
			{
				ss[i] = s1[j];
				mut.push_back(ss);
				j++;
			}
			else
			{
				j++;
			}
		}
		j = 0;
		i++;
	}
	return mut;
}

int ChisloMut(string v, string v1)
{
	int d = 0;
	for (int i = 0; i < v.length(); i++)
	{
		if (v[i] != v1[i])
			d++;
	}
	return d;
}

string Proverka1(string v1, vector<string> v, int d, int k)
{
	int p = 0, j = 0, d1, d111 = 0;
	string res = "";
	for (int i = 1; i < v.size(); i++)
	{
		string s = v[i];
		for (int j = 0; j < s.length(); j++)
		{
			p = 0;
			string s1 = "";
			while ((p < k) && (j < s.length()))
			{
				s1 += s[j];
				j++;
				p++;
			}
			if (s1.length() != k)
				break;
			d1 = ChisloMut(s1, v1);
			if (d1 <= d)
			{
				d111++;
				break;
			}
			else
			{
				j = j - k;
			}
		}
	}
	if (d111 == v.size() - 1)
		return v1;
	else
		return res;
}


vector<string> Proverka(vector<string> v1, vector<string> v, int k, int d)
{
	int t = 0, h = 0, d1;
	vector<string> prov;
	string s = "", s1 = "", res;
	for (int i = 0; i < v1.size(); i++)
	{
		int p = 0;

		if (i == 0)
		{
				s = v[i];
				for (int j = 0; j < s.length(); j++)
				{
					p = 0;
					s1 = "";
					while ((p < k) && (j < s.length()))
					{
						s1 += s[j];
						j++;
						p++;
					}
					if (s1.length() != k)
						break;
					d1 = ChisloMut(s1, v1[i]);
					if (d1 <= d)
					{
						res = Proverka1(v1[i], v, d, k);
						if (res != "")
						{
							prov.push_back(v1[i]);
							break;
						}
					}
					j = j - k;
				}
			h++;
		}
		else
		{
			res = Proverka1(v1[i], v, d, k);
			if (res != "")
			{
				prov.push_back(v1[i]);
			}
		}
	}
	return prov;
}


int main()
{
	string s = "4 1", s1 /*= "CACTGATCGACTTATC", s2 = "CTCCGACTTACCCCAC", s3 = "GTCTATCCCTGATGGC", s4 = "CAGGGTTGTCTTGTCT"*/, s5;
	int k, d, p = 0;
	vector<string> v, v1, res, res1;

	getline(cin, s);

	while(!cin.eof())
	{
		cin >> s1;
		v.push_back(s1);
	}

	//v.push_back(s1);
	//v.push_back(s2);
	//v.push_back(s3);
	//v.push_back(s4);

	string s11 = "";
	s11 += s[0];
	k = atoi(s11.c_str());
	s11 = "";
	s11 += s[2];
	d = atoi(s11.c_str());

	int t = 0;

	for (int i = 0; i < v[0].length(); i++)
	{

		s5 = "";
		p = 0;
		while ((p < k) && (i < v[0].length()))
		{
			s5 += v[0][i];
			i++;
			p++;
		}
		if (s5.length() != k)
			break;
		v1 = Mut(s5, d);
		res = Proverka(v1, v, k, d);
		if (!res.empty())
		{
			for (int j = 0; j < res.size(); j++)
				res1.push_back(res[j]);
			res.clear();
		}
		v1.clear();
		i = i - k;
	}

	sort(res1.begin(), res1.end());
	auto last = unique(res1.begin(), res1.end());
	res1.erase(last, res1.end());
	
	for (int i = 0; i < res1.size(); i++)
		cout << res1[i] << " ";

	return 0;
}