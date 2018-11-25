#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

int ProbT(string s)
{
	int j = 0, k = 0;
	while (j < s.length())
	{
		if (s[j] == '-')
		{
			k++;
			j++;
		}
		else
			j++;
	}
	return k;
}

int Proverka(int m, int *spectr, int raz) //встречается ли число в спектре
{
	for (int i = 0; i < raz; i++)
	{
		if (spectr[i] == m)
		{
			return 1;
			break;
		}
	}
	return 0;
}

int Summa(string str)
{
	int i = 0;
	int sum = 0;
	while (i < str.length())
	{
		string s5 = "";
		while ((str[i] != '-') && (i < str.length()))
		{
			s5 += str[i];
			i++;
		}
		sum += atoi(s5.c_str());
		i++;
	}
	return sum;
}

vector<string> Rasshir(vector<string> SS, int *sp, int raz, int *spectr, int raz1)
{
	vector<string> SS1, REZ;
	string s5;
	int i = 0, sum = 0;
	while (i < SS.size())
	{
		//SS1.clear();
		SS1.push_back(SS[i]);
		s5 = "";
		s5 += SS1[i];
		sum = Summa(s5);

		int m = 0;
		for (int j = 0; j < raz; j++)
		{
			m = sum + sp[j];
			if (Proverka(m, spectr, raz1) == 1)
			{
				string s7 = "";
				string ch = to_string(sp[j]);
				s7 = s5 + '-' + ch;
				REZ.push_back(s7);
			}
		}
		i++;
	}
	return REZ;
}

bool Vkl(vector<int> sum, int raz, int *spectr, int raz1)
{
	int k;
	int *spectr1;
	spectr1 = new int[raz1];
	for (int i = 0; i < raz1; i++)
	{
		spectr1[i] = spectr[i];
	}
	spectr1[0] = -1;
	spectr1[raz1 - 1] = -1;
	for (int i = 0; i < raz; i++)
	{
		k = 0;
		for (int j = 0; j < raz1; j++)
		{
			if (sum[i] == spectr1[j])
			{
				spectr1[j] = -1;
				k = 1;
				break;
			}
		}
		if(k == 0)
		{
			return false;
			break;
		}
	}
	return true;
}

string Result(string ch, int *spectr, int raz1)
{
	int i = 0, m, k, p = 0;
	vector<int> sum;
	string h = "";
	k = ProbT(ch);
	int *sp;
	sp = new int[k + 1];

	while (i < ch.length())
	{
		string s1 = "";
		m = 0;
		while ((ch[i] != '-') && (i < ch.length()))
		{
			s1 += ch[i];
			i++;
		}
		m = atoi(s1.c_str());
		i++;
		sp[p] = m;
		p++;
	}
	int t = 2, tt = 0, summa = 0;
	while (t < k + 1)
	{
		for (int i = 0; i < k + 1; i++)
		{
			summa += sp[i];
			tt++;
			if (tt == t)
			{
				sum.push_back(summa);
				summa = 0;
				i = i - t + 1;
				tt = 0;
			}
		}
		summa = 0;
		t++;
		tt = 0;
	}
	if (Vkl(sum, sum.size(), spectr, raz1) == true)
		h = h + ch + ' ';
	return h;
}

int main()
{
	string s, s1, s2 = "", smass = "57 71 87 97 99 101 103 113 114 115 128 129 131 137 147 156 163 186";
	int mass[] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
	int j = 0, k = 0, m, p = 0;
	getline(cin, s);

	k = Prob(s);

	//введенный спектр
	int *spectr;
	spectr = new int[k + 1];
	int k1 = k + 1;
	for (int i = 0; i < s.length(); i++)
	{
		s1 = "";
		m = 0;
		while ((s[i] != ' ') && (i < s.length()))
		{
			s1 += s[i];
			i++;
		}
		m = atoi(s1.c_str());
		spectr[p] = m;
		p++;
	}
	//
	 
	//находим пересечение строк
	for (int i = 2; i < s.length(); i++)
	{
		int k;
		s1 = "";
		while((s[i] != ' ') && (i < s.length()))
		{
			s1 += s[i];
			i++;
		}
		k = smass.find(s1);
		if (k > 0)
		{
			s2 += s1 + ' ';
		}
	}
	k = Prob(s2);
	p = 0;

	////sp - массив пересечения
	//s2 - строка пересечения
	int *sp;
	sp = new int[k];
	for (int i = 0; i < s2.length(); i++)
	{
		s1 = "";
		m = 0;
		while ((s2[i] != ' ') && (i < s2.length()))
		{
			s1 += s2[i];
			i++;
		}
		m = atoi(s1.c_str());
		sp[p] = m;
		p++;
	}
	///////
	vector<string> SS, REZ, REZ2;
	string s4 = "", s5 = "", s6 = "", s7 = "", s8, s9 = "";
	int sum = 0, K, R = 0;
	j = 0;
	while (j < s2.length() - 1)
	{
		int h = 0;
		K = 0;
		while (s2[j] != ' ')
		{
			s4 += s2[j];
			j++;
		}
		SS.clear();
		SS.push_back(s4);
		REZ.clear();
		REZ = Rasshir(SS, sp, k, spectr, k1);
		while (Summa(REZ[R]) != spectr[k1 - 1])
		{
			REZ = Rasshir(REZ, sp, k, spectr, k1);
			for (int i = 0; i < REZ.size(); i++)
				cout << REZ[i] << endl;
			cout << endl;
		}
		j++;
		s4 = "";
	}
	sort(REZ2.begin(), REZ2.end());
	auto last = unique(REZ2.begin(), REZ2.end());
	REZ2.erase(last, REZ2.end());

	for (int i = 0; i < REZ2.size(); i++)
	{
		cout << REZ2[i] << endl;
	}
	//////


	string hh;
	for (int i = 0; i < REZ2.size(); i++)
	{
		hh = hh + Result(REZ2[i], spectr, k1);
	}

	cout << hh;


	return 0;
}