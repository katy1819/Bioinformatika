#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string s, s1, s2;
	int n, j = 0;
	cout << "Введите строку: " << endl;
	getline(cin, s);
	n = s.length();
	for (int i = 0; i < n/3; i++)
	{
		s1 = "";
		while(j < n)
		{
			s1 += s[j];
			j++;
			if (j % 3 == 0)
				break;
		}
		if ((s1 == "UUU") || (s1 == "UUC"))
			s2 += "F";
		else if ((s1 == "UUA") || (s1 == "UUG") || (s1 == "CUU") || (s1 == "CUC") || (s1 == "CUA") || (s1 == "CUG"))
			s2 += "L";
		else if ((s1 == "AUU") || (s1 == "AUC") || (s1 == "AUA"))
			s2 += "I";
		else if ((s1 == "AAU") || (s1 == "AAC"))
			s2 += "N";
		else if ((s1 == "AAA") || (s1 == "AAG"))
			s2 += "K";
		else if ((s1 == "ACA") || (s1 == "ACC") || (s1 == "ACG") || (s1 == "ACU"))
			s2 += "T";
		else if ((s1 == "AGA") || (s1 == "AGG") || (s1 == "CGA") || (s1 == "CGC") || (s1 == "CGG") || (s1 == "CGU"))
			s2 += "R";
		else if ((s1 == "AGC") || (s1 == "AGU") || (s1 == "UCA") || (s1 == "UCC") || (s1 == "UCG") || (s1 == "UCU"))
			s2 += "S";
		else if ((s1 == "AUG"))
			s2 += "M";
		else if ((s1 == "CAA") || (s1 == "CAG"))
			s2 += "Q";
		else if ((s1 == "CAC") || (s1 == "CAU"))
			s2 += "H";
		else if ((s1 == "CCA") || (s1 == "CCC") || (s1 == "CCG") || (s1 == "CCU"))
			s2 += "P";
		else if ((s1 == "GAA") || (s1 == "GAG"))
			s2 += "E";
		else if ((s1 == "GAC") || (s1 == "GAU"))
			s2 += "D";
		else if ((s1 == "GCA") || (s1 == "GCC") || (s1 == "GCG") || (s1 == "GCU"))
			s2 += "A";
		else if ((s1 == "GGA") || (s1 == "GGC") || (s1 == "GGG") || (s1 == "GGU"))
			s2 += "G";
		else if ((s1 == "GUA") || (s1 == "GUC") || (s1 == "GUG") || (s1 == "GUU"))
			s2 += "V";
		else if ((s1 == "UAC") || (s1 == "UAU"))
			s2 += "Y";
		else if ((s1 == "UGC") || (s1 == "UGU"))
			s2 += "C";
		else if ((s1 == "UGG"))
			s2 += "W";
		else if ((s1 == "UAA") || (s1 == "UAG") || (s1 == "UGA"))
			break;
	}
	cout << "Белок: " << s2 << endl;
	return 0;
}