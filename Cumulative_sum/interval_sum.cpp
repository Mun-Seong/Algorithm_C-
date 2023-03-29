// Baekjoon
// 11659 구간 합 구하기 4

#include <iostream>

int	sum[100001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	// input
	int n, m, num;

	std::cin >> n >> m;
	for (int i=0;i<n;++i)
	{
		std::cin >> num;
		sum[i+1] = sum[i] + num;
	}
	
	// solution
	for (int i=0;i<m;++i)
	{
		int s, e;
		std::cin >> s >> e;
		std::cout << sum[e] - sum[s-1] << '\n';
		// std::end = time over then, use '\n'
	}

	return 0;
}