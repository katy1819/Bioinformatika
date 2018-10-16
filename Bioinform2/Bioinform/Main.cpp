#include <string>
#include <iostream>

using namespace std;

void main()
{
	string s, s1, s2, str, str1;
	int k1, g = 0, j = 0, k, z, max = 1, n, h = 0, l = 0, m, *z2, n1;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите строку: " << endl;
	getline(cin, s);
	n = s.length();
	z2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		z2[i] = 0;
	}
	cout << "¬ведите k - мер:" << endl;
	cin >> k1;
	while (g < n)
	{
		s1 = "";
		for (int j = 0; j < k1; j++)
		{
			if (s[g] != 0)
			{
				s1 += s[g];
				g++;
			}
			else
				break;
		}
		if (s1.length() != k1)
			break;
		cout << "k - mer: " << s1 << endl;
		cout << endl;
		z = 0;
		for (int i = 0; i < n; i++)
		{
			k = 0;
			for (int j = 0; j < k1; j++)
			{
				if (s1[j] == s[i])
				{
					k = k + 1;
					i = i + 1;
					if (j == k1 - 1)
						i = i - k1;
				}
				else
				{
					i = i - k;
					break;
				}
			}
			if (k == k1)
			{
				z = z + 1;;
			}
		}
		cout << "„исло вхождений: " << z << endl;
		if (max <= z)
		{
			if (max < z)
			{
				str = "";
				str += s1 + " ";
				max = z;
			}
			else
			{
				int p = 0;
				n1 = str.length();
				for (int i = 0; i < n1; i++)
				{
					k = 0;
					for (int j = 0; j < k1; j++)
					{
						if (s1[j] == str[i])
						{
							k = k + 1;
							i = i + 1;
							if (j == k1 - 1)
								i = i - k1;
						}
						else
						{
							i = i - k;
							break;
						}
					}
					if (k == k1)
					{
						p = p + 1;;
					}
				}
				if (p == 0)
					str += s1 + " ";
			}
		}
		g = g - k1 + 1;
	}
	cout << str << endl;
}
