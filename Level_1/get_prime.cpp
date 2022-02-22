#include <iostream>
using namespace std;

bool	check_prime(int n)
{
	if (n == 1) return (false);
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return (false);
	}
	return (true);
}

int main()
{
	int N, idx(0), ret(0);
	int *nums;

	cin >> N;
	nums = new int[N];
	while (idx < N)
		cin >> nums[idx++];
	for (int i = 0; i < N; i++)
	{
		if (check_prime(nums[i]))
			ret++;
	}
	cout << ret;
	delete[] nums;
}