#include <iostream>

using namespace std;

int get_binary(int n)
{
	int idx = 0;
	while (n != 0)
	{
		if (n % 2 == 1)
			cout << idx << ' ';
		n = n / 2;
		idx++;
	}
}

int main()
{
	int	T, n;
	int	tmp = 0;
	int	nums[10];

	cin >> T;
	while (T != tmp)
	{
		cin >> nums[tmp];
		tmp++;
	}
	tmp = 0;
	while (tmp < T)
	{
		get_binary(nums[tmp]);
		if (tmp != T - 1)
			cout << endl;
		tmp++;
	}
}