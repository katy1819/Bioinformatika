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

int Peresechenie(vector<int> v1, int n2, int *ss1, int M)
{
	int n = 0;
	int *ss;
	ss = new int[M];
	for (int i = 0; i < M; i++)
		ss[i] = ss1[i];
	vector<int> vv1;
	vv1 = v1;
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ss[j] == vv1[i])
			{
				n++;
				ss[j] = -1;
				break;
			}
		}
	}
	return n;
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

int LinPep(string REZ,int *spectr, int raz1)
{
	int i = 0, m, p = 0, k;
	k = ProbT(REZ);
	vector<int> sp, sum;
	while (i < REZ.length())
	{
		string s1 = "";
		m = 0;
		while ((REZ[i] != '-') && (i < REZ.length()))
		{
			s1 += REZ[i];
			i++;
		}
		m = atoi(s1.c_str());
		i++;
		sp.push_back(m);
		p++;
	}
	int t = 1, tt = 0, summa = 0;
	sum.push_back(0);
	while (t < k + 2)
	{
		if (t == 1)
		{
			for (int i = 0; i < k + 1; i++)
			{
				summa = sp[i];
				tt++;
				if (tt == t)
				{
					sum.push_back(summa);
					i = i - t + 1;
					tt = 0;
				}
			}
		}
		else
		{
			summa = 0;
			for (int i = 0; i < k + 1; i++)
			{
				summa += sp[i];
				tt++;
				if (tt == t)
				{
					sum.push_back(summa);
					i = i - t + 1;
					tt = 0;
					summa = 0;
				}
			}
		}
		summa = 0;
		t++;
		tt = 0;
	}
	int chislo = Peresechenie(sum, sum.size(), spectr, raz1);
	return chislo;
}

vector<string> Rasshir(vector<string> SS, vector<int> Sp, int raz, int *spectr, int raz1)
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
			m = sum + Sp[j];
			if (Proverka(m, spectr, raz1) == 1)
			{
				string s7 = "";
				string ch = to_string(Sp[j]);
				s7 = s5 + '-' + ch;
				REZ.push_back(s7);
			}
		}
		i++;
	}
	return REZ;
}



int main()
{
	int N, k, m, p = 0;
	string N1;
	getline(cin, N1);
	N = atoi(N1.c_str());
	string s, s1, s2 = "", smass = "57 71 87 97 99 101 103 113 114 115 128 129 131 137 147 156 163 186";;
	getline(cin, s);
	k = Prob(s);

	////делаем из строки массив из чисел спектра

	int *spectr; //введенный
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

	/////////////////////////////

	//находим пересечение строк
	for (int i = 2; i < s.length(); i++)
	{
		int k;
		s1 = "";
		while ((s[i] != ' ') && (i < s.length()))
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


	vector<int> Sp; //это вектор пересечения без повторений
	for (int i = 0; i < k; i++)
		Sp.push_back(sp[i]);

	sort(Sp.begin(), Sp.end());
	auto last1 = unique(Sp.begin(), Sp.end());
	Sp.erase(last1, Sp.end());
	////////

	/////строка пересечения без повторений
	string ss2 = "";
	for (int i = 0; i < Sp.size(); i++)
	{
		ss2 = ss2 + to_string(Sp[i]) + ' ';
	}

	s2 = ss2;

	//cout << s2;

	vector<string> SS, REZ, REZ2;
	vector<int> REZ3;
	int R = 0, t = 0;
	for (int i = 0; i < Sp.size(); i++)
		//SS.push_back(to_string(Sp[i])); //строки - пересечения (начальные)
		REZ.push_back(to_string(Sp[i]));
	//for(int i = 0; i < )
	//REZ = Rasshir(SS, Sp, Sp.size(), spectr, k1);
	while (Summa(REZ[R]) != spectr[k1 - 1])
	{
		REZ3.clear();
		REZ2.clear();
		for (int i = 0; i < REZ.size(); i++)
			REZ3.push_back(LinPep(REZ[i], spectr, k1)); //это вектор с кол-м пересечений
		//for (int i = 0; i < REZ.size(); i++)
			//cout << REZ[i] << "  " << REZ3[i] << endl;
		int max = 0, j, j1, t = 0;
		while (t < N)
		{
			j = 0;
			j1 = -1;
			while (j < REZ3.size())
			{
				if (REZ3[j] >= max)
				{
					max = REZ3[j];
					j1 = j;
				}
				j++;
			}
			if (j1 != -1)
			{
				REZ2.push_back(REZ[j1]);
			}
			else
				break;
			t++;
			REZ3[j1] = -1;
		}
		for (int k = 0; k < REZ3.size(); k++)
		{
			if (REZ3[k] == max)
				REZ2.push_back(REZ[k]);
		}
		REZ = Rasshir(REZ2, Sp, Sp.size(), spectr, k1);

		//cout << endl;
	}

	cout << REZ[0] << endl;

	//for (int i = 0; i < REZ.size(); i++)
		//cout << REZ[i] << endl;

	return 0;
}
