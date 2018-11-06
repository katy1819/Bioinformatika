#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	long int n;
	cin >> n;
	cout << n * (n - 1) << endl;
	unsigned int end_time = clock();
	cout << end_time;
	return 0;
}