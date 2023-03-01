#include <iostream>

using namespace std;

int count_666(int n)
{
	int ret(0), cnt(0), tmp(0);
	while (cnt != n)
	{
		tmp = ++ret;
		while (tmp)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else
				tmp /= 10;
		}
	}
	return (ret);
}

int main()
{
	int N;
	cin >> N;

	cout << count_666(N) << endl;	
}