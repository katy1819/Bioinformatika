#include <string>
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s1, s2, s3;
	int n, g = 0;
	cout << "Введите строку: " << endl;
	getline(cin, s1);
	n = s1.length();
	for (int i = n - 1; i > -1; i--)
	{
		s2 += s1[i];
	}
	cout << "Строка наоборот: " << s2 << endl;
	for (int j = 0; j < n; j++)
	{
		if (s2[j] == 'A')
			s2[j] = 'T';
		else if (s2[j] == 'T')
			s2[j] = 'A';
		else if (s2[j] == 'C')
			s2[j] = 'G';
		else if (s2[j] == 'G')
			s2[j] = 'C';
	}
	cout << "Результат: " << s2 << endl;
}
