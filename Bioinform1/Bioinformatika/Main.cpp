#include <iostream>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s, s1;
	int n, n1, k, z = 0;
	cout << "Введите подстроку: " << endl;
	getline(cin, s1);
	n1 = s1.length();
	cout << "Введите строку: " << endl;
	getline(cin, s);
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < n1; j++)
		{
			if (s1[j] == s[i])
			{
				k = k + 1;
				i = i + 1;
				if (j == n1 - 1)
					i = i - n1;
			}
			else
			{
				i = i - k;
				break;
			}
		}
		if (k == n1)
		{
			z = z + 1;;
		}
	}
	cout << "Число вхождений: " << z << endl;
}

