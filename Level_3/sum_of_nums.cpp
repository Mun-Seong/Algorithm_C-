#include <iostream>
#include <cmath>
using namespace std;

long long s;

int main()
{
	cin >> s;
	long long i = 1, c = 0;
	long long index =sqrt(s * 2);
	while (1)
	{
		c = index * (index + 1) / 2;
		if (c > s) index--;
		else
		{
			cout << index;
			return (0);
		}
	}
}