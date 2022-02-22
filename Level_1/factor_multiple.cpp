#include <iostream>
using namespace std;

int get_max_fac(int a, int b)
{
	for (int i = a; i <= a; i--)
	{
		if ((a%i==0) && (b%i==0))
			return (i);
	}
}

int get_min_mul(int a, int b)
{
	for (int i = 1; i <= b; i++)
	{
		if ((a * i) % b == 0)
			return (a * i);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << get_max_fac(a, b) << endl << get_min_mul(a, b);
}