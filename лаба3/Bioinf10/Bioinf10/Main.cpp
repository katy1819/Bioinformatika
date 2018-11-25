#include <iostream>
#include <string>

using namespace std;

int Prob(string s)
{
	int j = 0, k = 0;
	while (j < s.length())
	{
		if (s[j] == ' ')
		{
			k++;
			j++;
		}
		else
			j++;
	}
	return k;
}
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
	while (p < n)
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

int Peresechenie(int *v1, int n2, int *ss1, int M)
{
	int n = 0;
	int *vv1;
	vv1 = v1;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (ss1[i] == vv1[j])
			{
				n++;
				vv1[j] = -1;
				break;
			}
		}
	}
	return n;
}

int main()
{
	/////////это все для введенного белка
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
	///////////////

	for (int i = 0; i < n2; i++)
	{
		cout << v1[i] << " ";
	}

	cout << endl;
	//////запись в массив из чисел белка
	string spectr, sss1;
	getline(cin, spectr);
	int *ss1;
	int M = Prob(spectr), p = 0, m;
	ss1 = new int[M + 1];
	for (int i = 0; i < spectr.length(); i++)
	{
		sss1 = "";
		m = 0;
		while ((spectr[i] != ' ') && (i < spectr.length()))
		{
			sss1 += spectr[i];
			i++;
		}
		m = atoi(sss1.c_str());
		ss1[p] = m;
		p++;
	}

	//for (int i = 0; i < M+1; i++)
	//{
		//cout << ss1[i] << " ";
	//}

	int chislo = Peresechenie(v1, n2, ss1, M + 1);

	cout << chislo;

	return 0;
}