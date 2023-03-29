// Baekjoon
// 2559 수열

#include <iostream>

int sum[100001];

int main()
{
	// input
	int	n, k, num ,res(-9999);
	std::cin >> n >> k;
	for (int i=1;i<=n;++i)
	{
		std::cin >> num;
		// solution
		sum[i] = sum[i-1] + num;
		if (i >= k)
			res = std::max(sum[i] - sum[i-k], res);

	}
	std::cout << res << '\n';
}