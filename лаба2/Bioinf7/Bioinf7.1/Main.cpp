#include <iostream>
#include <string>

using namespace std;

string Perevorot(string s)
{
	string s1;
	s1 += s[s.length() - 1];
	for (int i = 0; i < s.length() - 1; i++)
		s1 += s[i];
	return s1;
}

string Spectr1(string s)
{
	string s2 = "", s3 = s, s4;
	int n = s.length(), k, t, g, p = 0;
	while(p < n)
	{
		k = 1;
		g = 1;
		while (k < n)
		{
			t = 0;
			while (t < g)
			{
				s2 += s3[t];
				t++;
			}
			s2 += ' ';
			g++;
			k++;
		}
		s4 = Perevorot(s3);
		s3 = s4;
		p++;
	}
	return s2;
}

void Sort(int *v1, int n)
{
	int v2;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		v2 = v1[i];
		j = i - 1;
		while ((j >= 0) && (v1[j] > v2))
		{
			v1[j + 1] = v1[j];
			j = j - 1;
		}
		v1[j + 1] = v2;
	}
}

int main()
{
	string s, s2;
	getline(cin, s);
	s2 = Spectr1(s);


	int v[20] = { 57, 71, 87, 97, 99, 101, 103, 113, 113, 114, 115, 128, 128, 129, 131, 137, 147, 156, 163, 186 };
	string s1 = "GASPVTCILNDKQEMHFRYW";
	int *v1, g = 0, n2, k = 0, sum = 0, pos;
	n2 = (s.length())*(s.length() - 1) + 2;
	v1 = new int[n2];
	for (int i = 0; i < n2; i++)
	{
		sum = 0;
		if (i == 0)
			v1[i] = 0;
		else if (i == n2 - 1)
		{
			k = 0;
			sum = 0;
			while (k < s.length())
			{
				pos = s1.find(s[k]);
				sum += v[pos];
				k++;
			}
			v1[i] = sum;
		}
		else
		{
			while ((k < (s2.length() - 1)) && (s2[k] != ' '))
			{
				pos = s1.find(s2[k]);
				sum += v[pos];
				k++;
			}
			if (s2[k] == ' ')
				k++;
			if (k == (s2.length() - 1))
			{
				break;
			}
			v1[i] = sum;
		}
	}

	Sort(v1, n2);

	for (int i = 0; i < n2; i++)
	{
		cout << v1[i] << " ";
	}

	return 0;
}